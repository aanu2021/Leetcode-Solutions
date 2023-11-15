class Solution {
    public List<Integer> majorityElement(int[] nums) {
        HashMap<Integer,Integer>freq = new HashMap<>();
        List<Integer> answer = new ArrayList<>();
        int n = nums.length;
        for(int i=0;i<nums.length;i++){
            if(freq.containsKey(nums[i])){
                freq.put(nums[i],1 + freq.get(nums[i]));
            }
            else{
                freq.put(nums[i],1);
            }
        }
        for(Map.Entry<Integer,Integer> e : freq.entrySet()){
            if(e.getValue() > (n/3)){
                answer.add(e.getKey());
            }
        }
        return answer;
    }
}