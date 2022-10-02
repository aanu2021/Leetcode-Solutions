/*

Time Complexity  : O(N*K*target)
Space Complexity : O(N*target)

Approach : Recursion + Memoization

*/

class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
//     int func(int i,int n,int k,int target){
        
//         if(i==n){
            
//             if(target==0){
                
//                 return 1;
                
//             }
            
//             else{
                
//                 return 0;
                
//             }
            
//         }
        
//         if(dp[i][target]!=-1){
            
//             return dp[i][target];
            
//         }
        
//         ll ans = 0LL;
        
//         for(int move = 1;move <= k;move++){
            
//             if(target >= move){
                
//                 ans = add(ans,(ll)func(i+1,n,k,target-move));
                
//             }
            
//         }
        
//         return dp[i][target] = (int)ans;
        
//    }
    
    int numRollsToTarget(int n, int k, int target) {
        
        ll dp[n+1][target+1];
        
        memset(dp,0LL,sizeof(dp));
        
        // Trivial Case //
        
        for(int i=1;i<=min(k,target);i++){
            dp[1][i] = 1LL;
        }
        
        // Transitions //
        
        for(int i=2;i<=n;i++){
            
            for(int j=1;j<=target;j++){
                
                for(int moves = 1 ; moves <= min(k,j);moves++){
                    
                    dp[i][j] = add(dp[i][j],dp[i-1][j-moves]);
                    
                }
                
            }
            
        }
        
        return dp[n][target];
        
    }
};