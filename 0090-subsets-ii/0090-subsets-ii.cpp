class Solution {
public:

    void helper(vector<int>& nums , int index, vector<vector<int>>& result, vector<int>& temp){

        if(index == nums.size()){
            result.push_back(temp);
            return;
        }


        temp.push_back(nums[index]);
        helper(nums , index+1 , result, temp);

        temp.pop_back();
        
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }

        helper(nums, index+1 , result, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin() , nums.end());

        helper(nums , 0 , result , temp);
        return result;            
    }
};