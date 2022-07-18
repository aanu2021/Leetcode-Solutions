class Solution {
public:
    
    typedef long long ll;
    
    int shortestSubarray(vector<int>& nums, int k) {
        
        ll n=nums.size();
        
        vector<ll>P(n,0LL);
        
        ll ans=n+1;
        
        for(ll i=0;i<n;i++){
            
            P[i]=(i-1>=0 ? P[i-1] : 0LL)+(ll)nums[i];
            
            if(P[i]>=k){
                
                ans=min(ans,i+1);
                
            }
            
        }
        
        deque<ll>q;
        
        for(ll i=0;i<n;++i){
            
            while(!q.empty() && P[i]<=P[q.back()]){
                
                q.pop_back();
                
            }
            
            while(!q.empty() && P[i]-P[q.front()]>=k){
                
                ans=min(ans,i-q.front());
                q.pop_front();
                
            }
            
            q.push_back(i);
            
        }
        
        if(ans==n+1){
            return -1;
        }else{
            return ans;
        }
        
    }
};