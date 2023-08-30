class Solution {
public:
    
    typedef long long ll;
    
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        ll answer = 0LL;
        int last = nums[n-1];
        for(int i=n-2;i>=0;i--){
            int req = (nums[i]/last);
            if(nums[i]%last) req++;
            last = nums[i]/req;
            answer += (ll)(req-1);
        }
        return answer;
    }
};