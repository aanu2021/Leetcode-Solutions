class Solution {
public:
    
    int maxSatisfaction(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        
        int maxSum = 0;
        int totalSum = 0;
        int currSum = 0;
        
        for(int i=0;i<n;i++){
            totalSum += currSum;
            totalSum += nums[i];
            currSum += nums[i];
            maxSum = max(maxSum,totalSum);
        }
        
        return maxSum;
    
    }
};

/*
    
    -9 -8 -1 0 5
    
    a*1 + b*2 + c*3 + d*4
    a*2 + b*3 + c*4 + d*5
    
    a + b + c + d
    
    currSum = 5
    totalSum = 10
    turn = 2
    
*/   