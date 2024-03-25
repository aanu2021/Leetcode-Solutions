class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] *= -1;
            }
            else{
                answer.push_back(abs(nums[i]));
            }
        }
        return answer;
    }
};