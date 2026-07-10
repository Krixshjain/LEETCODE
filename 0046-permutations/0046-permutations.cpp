class Solution {
public:

    void helper(vector<int>& nums , unordered_set<int>& used , vector<int>& temp , vector<vector<int>>& result){

        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            
            if(used.find(nums[i])!=used.end()){
                continue;
            }

            used.insert(nums[i]);
            temp.push_back(nums[i]);

            helper(nums , used , temp , result);

            temp.pop_back();
            used.erase(nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<int> used;
        
        helper(nums , used , temp , result);
        return result;
    }
};