class Solution {
public:
    
    typedef long long ll;
    
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        ll rsum = accumulate(nums.begin(),nums.end(),0LL);
        ll sum = rsum;
        ll lsum = 0LL;
        ll ans = 1e18;
        int index = -1;
        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            rsum-=nums[i];
            ll curr = abs((lsum/(i+1)) - (rsum/(n-i-1)));
            if(curr < ans){
                ans = curr;
                index = i;
            }
        }
        if(ans > (sum/n)){
            index = n-1;
        }
        return index;
    }
};

// 1 , 2 , 3 , 4 , 5
    
// 1  2 + 3 + 4 + 5 / 4  = 14/4 = 3
    