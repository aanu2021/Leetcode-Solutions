class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int>answer(n,0);
        vector<int>tails;
        tails.push_back(nums[0]);
        answer[0] = 1;
        for(int i=1;i<n;i++){
            if(tails.back() <= nums[i]){
                tails.push_back(nums[i]);
                answer[i] = tails.size();
            }
            else{
                int idx = upper_bound(tails.begin(),tails.end(),nums[i]) - tails.begin();
                tails[idx] = nums[i];
                answer[i] = idx + 1;
            }
        }
        return answer;
    }
};