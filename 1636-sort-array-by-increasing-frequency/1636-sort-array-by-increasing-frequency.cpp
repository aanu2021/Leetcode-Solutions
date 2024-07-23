class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int &ele : nums) freq[ele]++;
        vector<pair<int,int>>vec;
        for(auto &itr : freq){
            vec.push_back({itr.second, -itr.first});
        }
        sort(vec.begin(),vec.end());
        int idx = 0;
        for(int i=0;i<vec.size();i++){
            int ele = -vec[i].second;
            int occ = vec[i].first;
            while(occ--){
                nums[idx++] = ele;
            }
        }
        return nums;
    }
};