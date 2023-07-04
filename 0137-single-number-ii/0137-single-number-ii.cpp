class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>bits(32,0);
        
        for(int i=0;i<n;i++){
            int ele = nums[i];
            for(int j=31;j>=0;j--){
                if((ele&(1<<j))){
                    bits[j]++;
                }
            }
        }
        
        int answer = 0;
        for(int i=31;i>=0;i--){
            if(bits[i]%3){
                answer |= (1<<i);
            }
        }
        
        return answer;
        
    }
};