class Solution {
public:

    void helper(vector<int>& candidates , int index , int target , vector<int>& temp , vector<vector<int>>& result){

        if(target==0){
            result.push_back(temp);
            return;
        }

        if(target<0){
            return;
        }

        if(index == candidates.size()){
            return;
        }
        

        temp.push_back(candidates[index]);
        helper(candidates , index , target-candidates[index], temp , result);

        temp.pop_back();

        helper(candidates , index+1 , target , temp , result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int> temp;
        vector<vector<int>> result;

        helper(candidates , 0 , target , temp ,result);
        return result;
    }
};