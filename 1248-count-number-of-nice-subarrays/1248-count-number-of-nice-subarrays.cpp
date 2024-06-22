class Solution {
public:
    
    int isOdd(int num){
        return num%2 ? 1 : 0;
    }
    
    int func(vector<int>&nums, int k){
        int n = nums.size();
        int answer = 0;
        int l = 0, r = 0, currSum = 0;
        while(r < n){
            currSum += isOdd(nums[r]);
            while(l <= r && currSum > k){
                currSum -= isOdd(nums[l++]);
            }
            answer += max(0, r-l+1);
            r++;
        }
        return answer;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);    
    }
};

/*

1 1 0 1 1
    
currSum = 3    
answer = 2
    
freq[0] = 1
freq[1] = 1
freq[2] = 2
freq[3] = 1
freq[4] = 1  

*/