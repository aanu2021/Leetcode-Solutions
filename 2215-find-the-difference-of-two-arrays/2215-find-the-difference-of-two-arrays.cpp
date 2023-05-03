class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        unordered_set<int>S1,S2;
        for(int &ele : nums1) S1.insert(ele);
        for(int &ele : nums2) S2.insert(ele);
        for(auto &ele : S1){
            if(S2.find(ele) == S2.end()) ans[0].push_back(ele);
        }
        for(auto &ele : S2){
            if(S1.find(ele) == S1.end()) ans[1].push_back(ele);
        }
        return ans;
    }
};