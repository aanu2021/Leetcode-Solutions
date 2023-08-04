class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int>S;
        vector<int>ps(n,-1);
        vector<int>ns(n,n);
        for(int i=0;i<n;i++){
            while(!S.empty() && nums[i] <= nums[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                ps[i] = S.top();
            }
            S.push(i);
        }
        while(!S.empty()) S.pop();
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && nums[i] <= nums[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                ns[i] = S.top();
            }
            S.push(i);
        }
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int currArea = nums[i]*(ns[i]-ps[i]-1);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};