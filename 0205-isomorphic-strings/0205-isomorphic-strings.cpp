class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int> hashmaps;
        unordered_map<char,int> hashmapt;

        for(int i=0 ; i<s.length() ; i++){

            if(hashmaps.find(s[i]) == hashmaps.end()){
                hashmaps[s[i]] = i;
            }

            if(hashmapt.find(t[i]) == hashmapt.end()){
                hashmapt[t[i]] = i;
            }

            if(hashmaps[s[i]] != hashmapt[t[i]]) return false;
        }
        return true;
    }
};