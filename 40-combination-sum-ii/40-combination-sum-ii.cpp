class Solution {
public:
    
    vector<vector<int>>result;
    
    void func(vector<int>&nums,int i,int n,int target,vector<int>solution){
        
        if(target==0){
            result.push_back(solution);
            return;
        }
        
        if(i>=n || target<0){
            return;
        }
        
        
        for(int k=i;k<n;k++){
            
            if(k!=i && nums[k]==nums[k-1]){
                continue;
            }
            
            solution.push_back(nums[k]);
            
            func(nums,k+1,n,target-nums[k],solution);
            
            solution.pop_back();
            
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int>solution;
        
        func(nums,0,n,target,solution);
        
        sort(result.begin(),result.end());
        
        return result;
        
    }
};