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
        
        vector<ll>power(n+1,0LL);
        power[0] = 1LL;
        for(int i=1;i<=n;i++){
            power[i] = mul(power[i-1],2LL);
        }
        
        ll cntSubSeq = 0LL;
        int left = 0, right = n-1;
        
        while(left <= right){
            
            int currSum = nums[left] + nums[right];
            if(currSum <= target){
                cntSubSeq += power[right-left];
                cntSubSeq %= M;
                left++;
            }
            else{
                right--;
            }
            
        }
        
        return cntSubSeq;
        
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

a0 a1 a2 a3 a4 a5
i
            j

a0 + a5 > target
a1 >= a0
a1 + a5 > target
a2 + a5 > target

a0 + a4 <= target    add current possible number of subsequences
a1

a0 a1 a2 a3 a4

a0 + a4 <= target

pow(2,j-i)



a0 -> a1

*/