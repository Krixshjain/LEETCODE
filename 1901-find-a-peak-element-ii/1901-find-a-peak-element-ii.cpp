class Solution {
public:

    int maxrowinde(vector<vector<int>>& mat , int row , int col , int mid){
        int maxelement = INT_MIN;
        int index;
        for(int i=0 ; i<row ; i++){
            if(maxelement < mat[i][mid]){
                maxelement = mat[i][mid];
                index = i;
            }
            
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 0;
        int high = col-1;

        vector<int> ans;
        while(low<=high){

            int mid = (low+high)/2;
            int maxrowindex = maxrowinde(mat,row,col,mid);
            int left = mid-1 >= 0  ? mat[maxrowindex][mid-1] : -1;
            int right = mid+1 < col ? mat[maxrowindex][mid+1]: -1;

            if(left < mat[maxrowindex][mid] && right <mat[maxrowindex][mid]){
                ans.push_back(maxrowindex);
                ans.push_back(mid);
                return ans;
            }
            else if(left > mat[maxrowindex][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return {-1,-1};
    }
};