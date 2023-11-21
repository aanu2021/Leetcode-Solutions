class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    ll rev(int num){
        ll number = 0LL;
        while(num){
            int rem = (num%10);
            number = (number*10LL) + (ll)rem;
            num/=10;
        }
        return number;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll,int>freq;
        ll answer = 0LL;
        for(int i=0;i<n;i++){
            ll curr_contribution = (ll)nums[i] - rev(nums[i]);
            answer += freq[curr_contribution];
            answer %= M;
            freq[curr_contribution]++;
        }
        return answer;
    }
};

// nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    
// 42-24 = 18
// 11-11 = 0
// 1-1   = 0    
// 97-79 = 18     