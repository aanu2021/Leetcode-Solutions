class Solution {
public:
    
    typedef long long ll;
    
    long long maxAlternatingSum(vector<int>& nums) {
        
        ll n=nums.size();
        
        vector<ll>even(n,0LL);
        vector<ll>odd(n,0LL);
        
        even[0]=(ll)nums[0];
        odd[0]=0LL;
        
        ll maxval=even[0];
        
        for(ll i=1;i<n;i++){
            
            even[i]=max(even[i-1],odd[i-1]+(ll)nums[i]);
            odd[i]=max(odd[i-1],even[i-1]-(ll)nums[i]);
            
            maxval=max(maxval,even[i]);
            maxval=max(maxval,odd[i]);
            
        }
        
        return maxval;
        
    }
};