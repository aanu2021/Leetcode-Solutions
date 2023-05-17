class Solution {
public:
    
    typedef long long ll;
    
    long long maximumOr(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        ll answer = 0LL;
        
        vector<ll>prefix(n,0LL);
        vector<ll>suffix(n,0LL);
        
        prefix[0] = (ll)nums[0];
        suffix[n-1] = (ll)nums[n-1];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] | (ll)nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] | (ll)nums[i];
        }
        
        for(int i=0;i<n;i++){
            ll left = (i-1 >= 0 ? prefix[i-1] : 0LL);
            ll right = (i+1 < n ? suffix[i+1] : 0LL);
            ll ele = (ll)nums[i];
            ele *= pow(2LL,(ll)k);
            // cout<<ele<<" ";
            ll currOrValue = left | right | ele;
            // cout<<currOrValue<<"\n";
            answer = max(answer,currOrValue);
        }
        
        return answer;
        
    }
};