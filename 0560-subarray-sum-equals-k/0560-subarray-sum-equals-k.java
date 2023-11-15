class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int totalCount = 0;
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            if(map.containsKey(currSum-k)){
                totalCount += map.get(currSum - k);
            }
            if(map.containsKey(currSum)){
                map.put(currSum, map.get(currSum) + 1);
            }
            else{
                map.put(currSum,1);
            }
        }
        return totalCount;
    }
}