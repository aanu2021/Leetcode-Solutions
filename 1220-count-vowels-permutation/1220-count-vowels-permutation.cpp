 /*
        
        dp[i][0] --> stores count of i-length string , ends with character 'a'        
        
         dp[i][1] --> stores count of i-length string , ends with character 'e'
        
         dp[i][2] --> stores count of i-length string , ends with character 'i'
        
         dp[i][3] --> stores count of i-length string , ends with character 'o'
        
         dp[i][4] --> stores count of i-length string , ends with character 'u'
        
        
         Required Recurrences for solving the problem ......
        
        
        According to the question Each character 'a' may only be followed by 'e' .
        
        That means if character at i-th index be 'e' , then its one of the previous characters might be 'a'
        
        'a' --next--> 'e'
        'a' <--prev-- 'e'
        
        Now , the recurrence boils down to ---->
        
        for the character at i-th index , try to figure out all the possible (i-1)-th indexed characters.
        
        e.g : dp[i]['e'] = dp[i-1]['a'] + dp[i-1]['i']
        
        
        */


class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    int countVowelPermutation(int n) {
        
        vector<vector<ll>>dp(n+1,vector<ll>(5,0LL));
       
        // Base Case :
        
        dp[1][0]=1LL;
        dp[1][1]=1LL;
        dp[1][2]=1LL;
        dp[1][3]=1LL;
        dp[1][4]=1LL;
        
        // Transitions for recurrence :
        
        for(ll i=2;i<=n;++i){
            
            // For character 'a' 
            
            dp[i][0] = add(add(dp[i-1][1],dp[i-1][2]),dp[i-1][4]);
            
            // For character 'e'
            
            dp[i][1] = add(dp[i-1][0],dp[i-1][2]);
            
            // For character 'i'
            
            dp[i][2] = add(dp[i-1][1],dp[i-1][3]);
            
            // For character 'o'
            
            dp[i][3] = dp[i-1][2];
            
            // For character 'u'
            
            dp[i][4] = add(dp[i-1][2],dp[i-1][3]);
            
        }
        
        ll total = 0LL;
        
        for(ll i=0;i<5;++i){
            
            total=add(total,dp[n][i]);
            
          //  cout<<dp[n][i]<<" ";
            
        }cout<<"\n";
        
        return total;
        
    }
};