class Solution {
public:
    
    typedef long long ll;
    
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int minLen=n+1;
        
        vector<ll>prefix(n,0LL);
        
        prefix[0]=(ll)nums[0];
        
        for(ll i=1;i<n;++i){
            
            prefix[i]=prefix[i-1]+(ll)nums[i];
            
        }
        
        
        deque<int>q;
        
        for(int i=0;i<n;++i){
            
            if(prefix[i]>=k){
                
                minLen=min(minLen,i+1);
                
            }
            
            while(!q.empty() && prefix[q.back()]>=prefix[i]){
                
                q.pop_back();
                
            }
            
            while(!q.empty() && prefix[i]-prefix[q.front()]>=k){
                
                minLen=min(minLen,i-q.front());
                q.pop_front();
                
            }
            
            q.push_back(i);
            
        }
        
        return (minLen==n+1 ? -1 : minLen);
        
    }
};