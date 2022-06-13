class Solution {
public:
    
    vector<vector<int>>result;
    
    void func(vector<int>&nums,int i,int n,vector<int>&solution){
        
       result.push_back(solution);
        
       for(int k=i;k<n;k++){
           
           if(k!=i && nums[k]==nums[k-1]){
               continue;
           }
           
           solution.push_back(nums[k]);
           
           func(nums,k+1,n,solution);
           
           solution.pop_back();
           
       }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int>solution;
        
        func(nums,0,n,solution);
        
        sort(result.begin(),result.end());
        
        return result;
        
    }
};