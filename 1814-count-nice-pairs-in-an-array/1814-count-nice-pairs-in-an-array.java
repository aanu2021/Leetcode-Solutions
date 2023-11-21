class Solution {
    
    final long M = 1000000007;
    
    long rev(int num){
        long number = 0;
        while(num > 0){
            int rem = (num%10);
            number = (number*10L) + (long)rem;
            num /= 10;
        }
        return number;
    }
    
    public int countNicePairs(int[] nums) {
        int n = nums.length;
        long answer = 0L;
        HashMap<Long,Integer> freq = new HashMap<>();
        for(int i=0;i<n;i++){
            long curr_contribution = (long)nums[i] - rev(nums[i]);
            if(freq.containsKey(curr_contribution)){
                answer += freq.get(curr_contribution);
                answer %= M;
                freq.put(curr_contribution, freq.get(curr_contribution) + 1);
            }
            else{
                freq.put(curr_contribution, 1);
            }
        }
        return (int)answer;
    }
}