class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>S;
        int maxLen = 0;
        for(int &ele : nums){
            S.insert(ele);
        }
        for(int &ele : nums){
            if(S.find(ele) == S.end()) continue;
            S.erase(ele);
            int next = ele + 1;
            int prev = ele - 1;
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