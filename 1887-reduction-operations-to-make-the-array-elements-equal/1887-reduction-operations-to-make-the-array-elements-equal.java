class Solution {
    public int reductionOperations(int[] nums) {
        int answer = 0;
        int n = nums.length;
        int prevCnt = 0;
        Arrays.sort(nums);
        for(int i=n-1;i>=0;i--){
            answer += prevCnt;
            int j = i;
            while(j >= 0 && nums[j] == nums[i]){
                prevCnt++; j--;
            }
            i = j;
            i++;
        }
        return answer;
    }
}