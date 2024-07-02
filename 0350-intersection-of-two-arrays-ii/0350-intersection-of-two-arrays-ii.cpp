class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>answer;
        unordered_map<int,int>f1,f2;
        for(int &ele : nums1) f1[ele]++;
        for(int &ele : nums2) f2[ele]++;
        for(auto &itr : f1){
            int ele = itr.first;
            int occ = min(itr.second, f2[ele]);
            for(int o=1;o<=occ;o++){
                answer.push_back(ele);
            }
        }
        return answer;
    }
};