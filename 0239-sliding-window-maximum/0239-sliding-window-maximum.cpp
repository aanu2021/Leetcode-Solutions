class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>answer;
        deque<int>q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        answer.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[i] > nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            answer.push_back(nums[q.front()]);
        }
        return answer;
    }
};