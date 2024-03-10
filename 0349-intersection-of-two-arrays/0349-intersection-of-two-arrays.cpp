class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>f1,f2;
        for(int &ele : nums1) f1[ele]++;
        for(int &ele : nums2) f2[ele]++;
        vector<int>answer;
        for(auto &itr : f1){
            int ele = itr.first;
            if(f2[ele] > 0) answer.push_back(ele);
        }
        return answer;
    }
};