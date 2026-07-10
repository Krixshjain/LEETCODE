class Solution {
public:

    void helper(vector<int>& candidates , int index , int target, vector<vector<int>>& result , vector<int>& temp){



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
        helper(candidates, index+1 , target-candidates[index] , result , temp);

        temp.pop_back();

        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }

        helper(candidates , index+1 , target , result, temp);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(candidates.begin() , candidates.end());
        helper(candidates , 0 , target , result , temp);
        return result;
    }
};