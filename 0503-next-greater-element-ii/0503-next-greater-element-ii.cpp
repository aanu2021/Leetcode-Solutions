class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        stack<int>S;
        int m = nums.size();
        vector<int>answer(n,-1);
        for(int i=m-1;i>=0;i--){
            int idx = (i%n);
            while(!S.empty() && S.top() <= nums[i]){
                S.pop();
            }
            if(!S.empty()){
                answer[idx] = S.top();
            }
            S.push(nums[i]);
        }
        return answer;
    }
};