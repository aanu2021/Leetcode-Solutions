class Solution {
public:
    
    vector<vector<int>>ans;
    
    void func(vector<int>&nums,int idx,int n,vector<int>&solution){
        
        if(idx>=n){
            
            ans.push_back(solution);
            return;
            
        }
        
        func(nums,idx+1,n,solution);
        
        solution.push_back(nums[idx]);
        
        func(nums,idx+1,n,solution);
        
        solution.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        
        vector<int>solution;
        
        func(nums,0,n,solution);
        
        return ans;
        
    }
};