class Solution {
public:
    
    int func(vector<int>&nums, int n, int R, int D){
        unordered_map<int,int>freq;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            ele %= D;
            int rem = ((R - ele) + D) % D;
            int currLen = 1 + freq[rem];
            currLen = max(currLen, freq[ele]);
            maxLen = max(maxLen, currLen);
            freq[ele] = currLen;
        }
        return maxLen;
    }
    
    int maximumLength(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        for(int K=0;K<k;K++){
            maxLen = max(maxLen, func(nums, n, K, k));
        }
        return maxLen;
    }
};

// R = 3 
// D = 5
    
//     4 4