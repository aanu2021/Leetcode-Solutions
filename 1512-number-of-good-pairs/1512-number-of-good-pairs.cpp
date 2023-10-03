class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        int answer = 0;
        for(auto &itr : freq){
            int occ = itr.second;
            answer += (occ*(occ-1))/2;
        }
        return answer;
    }
};