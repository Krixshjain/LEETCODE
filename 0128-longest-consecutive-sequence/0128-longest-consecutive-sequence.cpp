class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0;
        unordered_set<int> map;
        if(nums.size()==0) return 0;
        
        for(int num:nums){
            map.insert(num);
        }
        for(int mum : map){
            if(map.find(mum-1) == map.end()){
                int curr = mum;
                int currst = 1;

                while(map.find(curr+1) != map.end()){
                    curr++;
                    currst++;
                }

                count = max(count,currst);
            }
        }
        return count;
    }
};