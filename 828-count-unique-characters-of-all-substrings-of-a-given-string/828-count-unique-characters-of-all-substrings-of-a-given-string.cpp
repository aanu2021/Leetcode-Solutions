class Solution {
public:
    
    typedef long long ll;
    
    int uniqueLetterString(string s) {
        
        int n=s.length();
        
        vector<int>left(n,-1);
        
        vector<int>right(n,n);
        
        map<char,int>mp;
        
        for(int i=0;i<n;i++){
            
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                left[i]=-1;
            }
            
            else{
                left[i]=mp[s[i]];
                mp[s[i]]=i;
            }
            
        }
        
        
        mp.clear();
        
        for(int i=n-1;i>=0;i--){
            
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                right[i]=n;
            }
            
            else{
                right[i]=mp[s[i]];
                mp[s[i]]=i;
            }
            
        }
        
        
        ll ans=0LL;
        
        for(ll i=0;i<n;i++){
            
            ll l=(i-left[i]);
            ll r=(right[i]-i);
            
            ans+=(ll)(l*r);
            
        }
        
        return ans;
        
    }
};