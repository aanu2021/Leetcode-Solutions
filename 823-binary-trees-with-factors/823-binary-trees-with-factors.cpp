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
    
    int numFactoredBinaryTrees(vector<int>& arr) {
       
        /*
        
        sort the array for simplicity sake
        
        arr : [2,4,5,10]
        
        dp  : [1,1,1,1]
        
        ans=0
            
        index[2] =0
        index[4] =1
        index[5] =2
        index[10]=3    
        
        dp[i] --> number of binary trees rooted at node i.
            
        // traverse through all the node values , which might be a potential candidate as its divisor.    
            
        for(int j=0;j<i;++j){
            
            if(arr[i]%arr[j]==0){
                
                int rest=(arr[i]/arr[j]);
                
                if the remainder already exists in the array , then ---->
                    
                number of ways to build binary tree , rooted at i depends upon its children arr[j] && rest , Now the problem boils down to number of ways to form B.T rooted at i is the summation of number of ways to form B.T rooted at its left and right child.
                    
               dp[i]+=(dp[j]*dp[index[rest]]);     
                
            }
            
        }    
        
        */
        
        
        ll n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        // For a node i , its divisors should be less than or equal to it , that is why we gonna sort the array for simplicity sake.
        
        
        
        vector<ll>dp(n,1LL);
        
// dp[i] --> # of ways to form different B.T s rootd at node i.
        
        
        
        unordered_map<ll,ll>index;
        
        // stores the corresponding index of each and every element. That will help us directly filling the DP table later on.
        
        for(ll i=0;i<n;++i){
            
            index[arr[i]]=i;
            
        }
        
        
        for(ll i=1;i<n;++i){
            
            for(ll j=0;j<i;++j){
                
                if(arr[i]%arr[j]==0){
                    
                    ll rest=(arr[i]/arr[j]);
                    
                    if(index.find(rest)!=index.end()){
                        
                            dp[i]=add(dp[i],mul(dp[j],dp[index[rest]]));
                        
                        
                    }
                    
                }
                
            }            
            
        }
        
        
        ll total_ways=0LL;
        
        for(ll i=0;i<n;++i){
            
            total_ways=add(total_ways,dp[i]);
            
        }
        
        return total_ways;
            
    }
};