class Solution {
    
    boolean isArithmeticSubarray(List<Integer>nums){
        int n = nums.size();
        HashSet<Integer>S = new HashSet<>();
        int minElement = nums.get(0);
        int maxElement = nums.get(0);
        for(int num : nums){
            minElement = Math.min(minElement, num);
            maxElement = Math.max(maxElement, num);
        }
        if((maxElement-minElement)%(n-1) != 0) return false;
        int D = (maxElement - minElement)/(n - 1);
        if(D == 0){
            for(int num : nums){
                S.add(num);
            }
            return S.size() == 1 ? true : false;
        }
        else{
            for(int num : nums){
                if((num-minElement)%D != 0) return false;
                int index = (num - minElement)/D;
                if(S.contains(index)) return false;
                S.add(index);
            }
            return true;
        }
    }
    
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = nums.length;
        int m = l.length;
        List<Boolean>answer = new ArrayList<>();
        for(int i=0;i<m;i++){
            int left = l[i];
            int right = r[i];
            List<Integer> list = new ArrayList<>();
            for(int idx=left;idx<=right;idx++){
                list.add(nums[idx]);
            }
            answer.add(isArithmeticSubarray(list));
        }
        return answer;
    }
}