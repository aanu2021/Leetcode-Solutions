class Solution {
public:
    
    void func(vector<int>&nums, int index, int n, vector<vector<int>>& answer){
        if(index == n){
            answer.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i], nums[index]);
            func(nums, index+1, n, answer);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>answer;
        func(nums,0,n,answer);
        return answer;
    }
};

