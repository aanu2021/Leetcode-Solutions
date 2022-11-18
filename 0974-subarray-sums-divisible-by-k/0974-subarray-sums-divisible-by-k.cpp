class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        mp[0] = 1;
        int ans = 0;
        int currsum = 0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            currsum = (((currsum+k)%k)+k)%k;
            ans+=mp[currsum];
            mp[currsum]++;
        }
        return ans;
    }
};