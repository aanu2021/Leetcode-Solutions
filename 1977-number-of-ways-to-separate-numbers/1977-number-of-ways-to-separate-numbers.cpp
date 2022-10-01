class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll add(ll a,ll b){
        
        ll c = (a+b);
        c += M;
        c %= M;
        return c;
        
    }
    
    bool Common(string &s,int i,int j,int len,vector<vector<int>>&same){
        
        int n = s.length();
        
        int common = same[i][j];
        
        if(common >= len) return true;
        
        if(j+common < n && s[i+common] < s[j+common]) return true;
        
        return false;
        
    }
    
    int numberOfCombinations(string s) {
        
        int n = s.length();
        
        if(s[0]=='0') return 0;
        
        vector<vector<int>>same(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s[i]==s[j]){
                    same[i][j] = same[i+1][j+1] + 1;
                }
            }
        }
        
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<same[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
        vector<vector<ll>>pref(n,vector<ll>(n,0LL));
        
        for(int j=0;j<n;++j){
            pref[0][j] = 1LL;
        }
        
        for(int i=1;i<n;++i){
            
            if(s[i]=='0'){
                
                pref[i] = pref[i-1];
                continue;
                
            }
            
            for(int j=i;j<n;++j){
                
                int len = (j-i+1);
                
                int prevstart = i-len;
                
                ll currsum = 0LL;
                
                if(prevstart < 0){
                    
                    currsum = pref[i-1][i-1];
                    
                }
                
                else{
                    
                    currsum = add(pref[i-1][i-1] , -pref[prevstart][i-1]);
                    
                    if(Common(s,prevstart,i,len,same)){
                        
                        if(prevstart==0){
                            
                            currsum = add(currsum , pref[prevstart][i-1]);
                            
                        }
                        
                        else{
                            
                            currsum = add(currsum , add(pref[prevstart][i-1],-pref[prevstart-1][i-1]));
                            
                        }
                        
                    }
                    
                }
                
                pref[i][j] = add(pref[i-1][j] , currsum);
            }
            
        }
        
        return pref[n-1][n-1];
        
    }
};