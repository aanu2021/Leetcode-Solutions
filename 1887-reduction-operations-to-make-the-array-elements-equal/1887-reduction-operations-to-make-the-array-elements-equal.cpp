class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int answer = 0;
        int prevCnt = 0;
        for(int i=0;i<n;i++){
            answer += prevCnt;
            int j = i;
            while(j<n && nums[j]==nums[i]){
                prevCnt++;
                j++;
            }
            i = j;
            i--;
        }
        return answer;
    }
};


// 5,5,5,3,3,1
// 3,3,3,3,3,1    