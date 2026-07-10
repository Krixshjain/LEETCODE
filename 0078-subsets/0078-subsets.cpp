class Solution {
public:

    void find(vector<int> &nums,int index , vector<int>& temp , vector<vector<int>>& result){

        if(index == nums.size()){
            result.push_back(temp);
            return;
        }   
        
        temp.push_back(nums[index]);
        find(nums , index+1 , temp , result);

        temp.pop_back();

        find(nums,index+1 , temp , result);


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;

        find(nums , 0 , temp, result);
        return result;
    }
};