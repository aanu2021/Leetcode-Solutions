class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(vector<int>&nums,int i,int n,int target,vector<int>&solution){
        
        if(target < 0) return;
        if(target == 0) answer.push_back(solution);
        
        for(int j=i;j<n;j++){
            if(j != i && nums[j]==nums[j-1]) continue;
            solution.push_back(nums[j]);
            recursion(nums,j+1,n,target-nums[j],solution);
            solution.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        int n = nums.size();
        answer.clear();
        sort(nums.begin(),nums.end());
        vector<int>solution;
        recursion(nums,0,n,target,solution);
        return answer;
    }
};


// target = 8
// 1 1 2 5 6 7 10
// 0 1 2 3 4 5 6
    
    