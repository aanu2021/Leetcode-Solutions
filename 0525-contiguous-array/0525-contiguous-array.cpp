class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0, currSum = 0;
        unordered_map<int,int>indexMap;
        indexMap[0] = -1;
        for(int i=0;i<n;i++){
            currSum += (nums[i]==1 ? 1 : -1);
            if(indexMap.find(currSum) != indexMap.end()){
                maxLen = max(maxLen, i - indexMap[currSum]);
            }
            else{
                indexMap[currSum] = i;
            }
        }
        return maxLen;
    }
};