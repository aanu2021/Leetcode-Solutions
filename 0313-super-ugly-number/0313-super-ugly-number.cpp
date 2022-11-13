class Solution {
public:
    
    typedef long long ll;
    
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        
        int m = primes.size();
        vector<ll>pointer(m,0LL);
        
        vector<ll>dp(n,0LL);
        dp[0] = 1LL;
        
        for(int i=1;i<n;i++){
            ll mini = LONG_MAX;
            for(int j=0;j<m;j++){
                mini = min(mini,dp[pointer[j]]*primes[j]);
            }
            dp[i] = mini;
            for(int j=0;j<m;j++){
                if((primes[j]*dp[pointer[j]])==mini){
                    pointer[j]++;
                }
            }
        }
        
        return dp[n-1];
        
    }
    
    struct Pair{
        ll value;
        ll prime;
        ll pointer;
    };
    
    struct comp{
       bool operator()(const Pair&x,const Pair&y){
           return x.value > y.value;
       }  
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int m = primes.size();
        
        vector<ll>dp(n,0LL);
        dp[0] = 1LL;
        
        int i = 1;
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        for(int i=0;i<m;i++){
            pq.push({primes[i],primes[i],0LL});
        }
        
        while(i<n){
            auto curr = pq.top();
            pq.pop();
            ll curr_value = curr.value;
            if(curr_value!=dp[i-1]){
                dp[i++] = curr_value;
            }
            pq.push({curr.prime*dp[curr.pointer+1],curr.prime,curr.pointer+1});
        }
        
        return dp[n-1];
        
    }
    
};