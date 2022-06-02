class Solution {
public:
    string longestPrefix(string s) {
        
        int n=s.length();
        
        vector<int>lps(n,0);
        
        int j=0;
        
        lps[0]=0;
        
        for(int i=1;i<n;i++){
            
            int len=lps[i-1];
            
            while(len>0 && s[len]!=s[i]){
                len=lps[len-1];
            }
            
            if(s[i]==s[len]){
                len++;
            }
            
            lps[i]=len;
            
        }
        
        return s.substr(0,lps[n-1]);
        
    }
};