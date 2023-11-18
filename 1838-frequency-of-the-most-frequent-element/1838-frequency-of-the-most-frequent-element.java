class Solution {
    
    public long func(int[] nums,int l,int r,long currSum){
        long ops = (r-l+1)*nums[r];
        ops -= currSum;
        return ops;
    }
    
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int l = 0, r = 0, maxLen = 0;
        long currSum = 0;
        while(r < n){
            currSum += (long)(nums[r]);
            while(l <= r && func(nums,l,r,currSum) > k){
                currSum -= (long)nums[l];
                l++;
            }
            maxLen = Math.max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
}