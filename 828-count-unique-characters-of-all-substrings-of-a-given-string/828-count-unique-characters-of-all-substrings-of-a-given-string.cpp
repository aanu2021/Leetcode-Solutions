class Solution {
public:
    int uniqueLetterString(string s) {
        
        int n=s.length();
        
        vector<int>prev(n,-1);
        
        vector<int>index(26,-1);
        
        for(int i=0;i<n;++i){
            
            prev[i]=index[s[i]-'A'];
            
            index[s[i]-'A']=i;
            
        }
        
        for(int i=0;i<26;++i){
            
            index[i]=n;
            
        }
        
        vector<int>next(n,n);
        
        for(int i=n-1;i>=0;i--){
            
            next[i]=index[s[i]-'A'];
            
            index[s[i]-'A']=i;
            
        }
        
        // for(int i=0;i<n;++i){
        //     cout<<prev[i]<<" ";
        // }cout<<"\n";
        
        int ans=0;
        
        for(int i=0;i<n;++i){
            
            ans+=(i-prev[i])*(next[i]-i);
            
        }
        
        return ans;
        
    }
};