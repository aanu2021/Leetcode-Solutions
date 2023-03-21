class Solution {
public:
    
    typedef long long ll;
    
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        ll answer = 0LL;
        for(int i=0;i<n;i++){
            if(nums[i] != 0) continue;
            int j = i;
            ll cnt = 0LL;
            while(j<n && nums[j]==nums[i]){
                cnt++; j++;
            }
            answer += (cnt*(cnt+1))/2LL;
            i = j;
            i--;
        }
        return answer;
    }
};