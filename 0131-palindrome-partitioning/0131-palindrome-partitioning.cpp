class Solution {
public:

    bool ispalindrome(string& s , int start , int end){
       while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
       }
       return true;
    }


    void helper(string& s , int index , vector<vector<string>>& result, vector<string>& temp){

        if(index == s.size()){
            result.push_back(temp);
            return;
        }

        for(int i= index ; i<s.size() ; i++){
            if(ispalindrome(s , index , i)){
                temp.push_back(s.substr(index , i - index + 1));
                helper(s , i+1 , result , temp);
                temp.pop_back();
            }
        }
        

        
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;

        helper(s , 0 , result , temp);
        return result;
    }
};