class Solution {
public:
    
    vector<vector<int>>result;
    
    void func(vector<int>&nums,int i,vector<int>&solution){
        
        result.push_back(solution);
        
        for(int k=i;k<nums.size();k++){
            
            if(k!=i && nums[k]==nums[k-1]){
                continue;
            }
            
            solution.push_back(nums[k]);
            
            func(nums,k+1,solution);
            
            solution.pop_back();
            
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        vector<int>solution;
        
        func(nums,0,solution);
        
        return result;
        
    }
};