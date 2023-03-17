class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int r = 0;
        int n = strs.size();
        for(string &str : strs){
            int len = str.length();
            r = max(r,len);
        }
        vector<vector<int>>vec(r,vector<int>(26,0));
        for(int i=0;i<n;i++){
            int len = strs[i].length();
            for(int j=0;j<len;j++){
                vec[j][strs[i][j]-'a']++;
            }
        }
        int maxLen = 0;
        for(int i=0;i<strs[0].length();i++){
            char ch = strs[0][i];
            if(vec[i][ch-'a'] == n){
                maxLen++;
                continue;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0,maxLen);
    }
};