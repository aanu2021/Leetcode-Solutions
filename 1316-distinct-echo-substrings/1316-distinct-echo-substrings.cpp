class Solution {
public:
    int distinctEchoSubstrings(string s) {
        
        int n=s.length();
        
        set<string>st;
        
        for(int len=1;len<=n/2;len++){
            
            int count=0;
            
            for(int l=0,r=len;r<n;l++,r++){
                
                if(s[l]==s[r]){
                    count++;
                }else{
                    count=0;
                }
                
                if(count==len){
                    count--;
                    st.insert(s.substr(l,r-l));
                }
                
            }
            
        }
        
        return st.size();
        
    }
};