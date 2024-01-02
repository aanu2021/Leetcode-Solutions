class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        int maxFreq = 0;
        for(auto &itr : freq) maxFreq = max(maxFreq, itr.second);
        vector<vector<int>>answer(maxFreq);
        for(auto &itr : freq){
            int ele = itr.first;
            int occ = itr.second;
            for(int i=0;i<occ;i++){
                answer[i].push_back(ele);
            }
        }
        return answer;
    }
};