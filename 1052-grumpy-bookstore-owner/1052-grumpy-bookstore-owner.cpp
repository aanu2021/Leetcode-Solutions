class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& G, int K) {
        
        int n = nums.size();
        vector<int>total(n+1, 0);
        vector<int>prefix(n+1, 0);
        vector<int>suffix(n+1, 0);
        
        int currSum = 0, totalSum = 0;
        for(int i=0;i<n;i++){
            if(G[i] == 0) currSum += nums[i];
            prefix[i] = currSum;
            totalSum += nums[i];
            total[i] = totalSum;
        }
        currSum = 0;
        for(int i=n-1;i>=0;i--){
            if(G[i] == 0) currSum += nums[i];
            suffix[i] = currSum;
        }
        
        int maxSum = 0;
        for(int i=0;i<=n-K;i++){
            int j = i+K-1;
            currSum = (i > 0 ? prefix[i-1] : 0) + (j+1 < n ? suffix[j+1] : 0) + total[j] - (i > 0 ? total[i-1] : 0);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
        
    }
};

// 1 0 1 2 1 1 7 5
    
// 0 1 0 1 0 1 0 1
    
// k = 3