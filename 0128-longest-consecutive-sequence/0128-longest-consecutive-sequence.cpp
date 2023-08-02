class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>S;
        for(int i=0;i<n;i++){
            S.insert(nums[i]);
        }
        int maxLen = 0;
        for(int &ele : nums){
            if(S.find(ele) == S.end()) continue;
            S.erase(ele);
            int currLen = 1;
            int prev = ele - 1;
            int next = ele + 1;
            while(S.find(prev) != S.end()){
                S.erase(prev);
                prev--;
            }
            while(S.find(next) != S.end()){
                S.erase(next);
                next++;
            }
            maxLen = max(maxLen, next - prev - 1);
        }
        return maxLen;
    }
};