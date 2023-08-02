class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(vector<int>&nums,int i,int n,int target,vector<int>&solution){
        if(target < 0) return;
        if(i==n){
           if(target == 0){
               answer.push_back(solution);
           } 
           return; 
        }
        recursion(nums,i+1,n,target,solution);
        solution.push_back(nums[i]);
        recursion(nums,i,n,target-nums[i],solution);
        solution.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>solution;
        recursion(nums,0,n,target,solution);
        return answer;
    }
};