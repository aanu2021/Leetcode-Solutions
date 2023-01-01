class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            while(len>0 && s[i]!=s[len]){
                len = lps[len-1];
            }
            if(s[i]==s[len]) len++;
            lps[i] = len;
        }
        return s.substr(0,lps[n-1]);
    }
};