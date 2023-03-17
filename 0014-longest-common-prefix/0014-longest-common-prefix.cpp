class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int maxLen = 0;
        int n = strs.size();
        int len1 = strs[0].length();
        int len2 = strs[n-1].length();
        int len = min(len1,len2);
        for(int i=0;i<len;i++){
            if(strs[0][i] == strs[n-1][i]){
                maxLen++;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0,maxLen);
    }
};