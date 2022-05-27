class Solution {
public:
    
    typedef long long ll;
    
    struct Pair{
      
        ll prime;
        ll pointer;
        ll value;
        
    };
    
    struct comp{
        
      bool operator()(Pair &x,Pair &y){
          return x.value > y.value;
      }  
        
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int dp[n];
        
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        for(int i=0;i<primes.size();i++){
            pq.push({primes[i],0,primes[i]});
        }
        
        for(int i=1;i<n;){
            
            auto curr=pq.top();
            pq.pop();
            
            if(curr.value!=dp[i-1]){
                
                dp[i]=curr.value;
                
                i++;
                
            }
            
            pq.push({curr.prime,curr.pointer+1,curr.prime*dp[curr.pointer+1]});
            
        }
        
        return dp[n-1];
        
    }
};