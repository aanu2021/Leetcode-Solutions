class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n=s.length();
        
        if(n<k){
            return false;
        }
        
        set<int>st;
        
        int hash=0;
        
        for(int i=0;i<k;i++){
            
            hash=(hash*2)+(s[i]-'0');
            
        }
        
        st.insert(hash);
        
        int powarr[k+1];
        
        powarr[0]=1;
        
        for(int i=1;i<=k;i++){
            powarr[i]=powarr[i-1]*2;
        }
        
        for(int i=k;i<n;i++){
            
            hash-=((s[i-k]-'0')*powarr[k-1]);
            
            hash*=2;
            
            hash+=(s[i]-'0');
            
            st.insert(hash);
            
        }
        
        return st.size()==(1<<k);
        
    }
};