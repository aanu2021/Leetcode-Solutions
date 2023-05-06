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
    ll modPow(ll a,ll b){
        if(b==0) return 1LL;
        if(b==1) return a;
        ll res = 1LL;
        while(b){
            if(b%2) res = mul(res,a);
            a = mul(a,a);
            b/=2;
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        ll ans = 0LL;
        for(int i=0;i<n;i++){
            
            int ele = nums[i];
            if(2*ele > target) break;
            
            int j = upper_bound(nums.begin()+i,nums.end(),target-ele) - nums.begin();
            int cntEle = (j-i-1);
            // cout<<cntEle<<"\n";
            
            ans += modPow(2LL,(ll)cntEle);
            ans %= M;
            
        }
        return ans;
    }
};

/*

min max

min + max <= target

sort

a0 a1 a2 a3 a4 a5

a0 + a4 > target

a0,a1,a2,a3

a0 (2^3) = 8 + 
    
a0 _
a0 a1
a0 a2
a0 a3
a0 a1 a2
a0 a1 a3
a0 a2 a3
a0 a1 a2 a3

*/