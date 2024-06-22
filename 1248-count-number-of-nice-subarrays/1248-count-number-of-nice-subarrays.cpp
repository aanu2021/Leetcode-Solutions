class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int currSum = 0, answer = 0;
        freq[0] = 1;
        for(int i=0;i<n;i++){
            currSum += (nums[i]%2 ? 1 : 0);
            answer += freq[currSum-k];
            freq[currSum]++;
        }
        return answer;
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