class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.length();
        int n = s2.length();
        int len = s3.length();
        
        if((m+n) != len) return false;
        
        vector<int>prev(n+1,false);
        prev[0] = true;
        
        for(int i=1;i<=n;i++){
            if(s2[i-1]==s3[i-1]){
                prev[i] = prev[i-1];
            }
        }
        
        for(int i=1;i<=m;i++){
            vector<int>curr(n+1,false);
            if(prev[0] && (s1[i-1]==s3[i-1])){
                curr[0] = true;
            }
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s3[i+j-1]){
                    curr[j] = prev[j];
                }
                if(s2[j-1]==s3[i+j-1]){
                    curr[j] = curr[j] || curr[j-1];
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        
        return prev[n];
        
    }
};