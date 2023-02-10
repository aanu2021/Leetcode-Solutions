class Solution {
public:
    
    int fun(vector<int>&nums){
        int n = nums.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>S;
        for(int i=0;i<n;i++){
            while(!S.empty() && nums[i] <= nums[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                left[i] = S.top();
            }
            S.push(i);
        }
        while(!S.empty()){
            S.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && nums[i] <= nums[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                right[i] = S.top();
            }
            S.push(i);
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            int curr = nums[i] * (right[i]-left[i]-1);
            maxi = max(maxi,curr);
        }
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>grid(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = matrix[i][j] - '0';
            }
        }
        int maxArea = fun(grid[0]);
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    grid[i][j] += grid[i-1][j];
                }
            }
            maxArea = max(maxArea,fun(grid[i]));
        }
        return maxArea;
    }
};