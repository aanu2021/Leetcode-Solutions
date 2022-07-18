class Solution {
public:
    
    typedef long long ll;
    
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<ll>P(n+1,0);
        
        for(int i=0;i<n;i++){
            P[i+1]=P[i]+(ll)nums[i];
        }
        
        int ans=INT_MAX;
        
        deque<int>q;
        
        for(int y=0;y<P.size();y++){
            
            while(!q.empty() && P[y]<=P[q.back()]){
                q.pop_back();
            }
            
            while(!q.empty() && P[y]-P[q.front()]>=k){
                ans=min(ans,y-q.front());
                q.pop_front();
            }
            
            q.push_back(y);
            
        }
        
        if(ans==INT_MAX){
            return -1;
        }
        
        else{
            return ans;
        }
        
    }
};