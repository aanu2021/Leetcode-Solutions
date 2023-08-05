class Solution {
public:
    int strStr(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(n < m) return -1;
        vector<int>lps(m,0);
        
        for(int i=1;i<m;i++){
            int len = lps[i-1];
            while(len && t[len] != t[i]){
                len = lps[len-1];
            }
            if(t[len] == t[i]){
                len++;
            }
            lps[i] = len;
        }
        
        int j = 0;
        
        for(int i=0;i<n;i++){
            if(s[i]==t[j]){
                j++;
                if(j==m){
                  return i-m+1;
                }
            }
            else{
                while(j && s[i] != t[j]){
                    j = lps[j-1];
                }
                if(s[i] == t[j]){
                    j++;
                }
            }
        }
        
        return -1;
    }
};