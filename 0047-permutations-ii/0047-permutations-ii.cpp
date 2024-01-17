class Solution {
public:
    
    void func(vector<int>& nums, int index, int n, vector<vector<int>>& answer){
        if(index == n){
            answer.push_back(nums);
            return;
        }
        unordered_set<int>S;
        for(int i=index;i<n;i++){
            if(S.find(nums[i]) != S.end()) continue;
            S.insert(nums[i]);
            swap(nums[i], nums[index]);
            func(nums, index+1, n, answer);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>answer;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        func(nums,0,n,answer);
        return answer;
    }
};