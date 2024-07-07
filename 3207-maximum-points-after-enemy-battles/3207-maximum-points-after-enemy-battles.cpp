class Solution {
public:
    
    typedef long long ll;
    
    long long maximumPoints(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(k < nums[0]) return 0LL;
        ll currPoints = (k/nums[0]), maxPoints = currPoints;
        k %= nums[0];
        for(int i=n-1;i>0;i--){
            k += nums[i];
            currPoints += (k/nums[0]);
            k %= nums[0];
        }
        return currPoints;
    }
};

// currentEnergy = 3
// points = 1    

// 2 2 3
// 0 1 2
// L
//   R

    
    