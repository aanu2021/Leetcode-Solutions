class Solution {
public:
    
    vector<vector<int>>answer;
    
    void func(vector<int>&nums,int i,int target,int n,vector<int>&solution){
        if(target < 0) return;
        if(target == 0){
            answer.push_back(solution);
            return;
        }
        for(int j=i;j<n;j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            solution.push_back(nums[j]);
            func(nums,j+1,target-nums[j],n,solution);
            solution.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        int n = nums.size();
        answer.clear();
        sort(nums.begin(),nums.end());
        vector<int>solution;
        func(nums,0,target,n,solution);
        return answer;
        
    }
};