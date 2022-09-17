class Solution {
public:
    
    vector<vector<int>>ans;
    
    void func(vector<int>&nums,int i,int n,vector<int>&solution){
        
        ans.push_back(solution);
        
        for(int j=i;j<n;++j){
            
           if(j!=i && nums[j]==nums[j-1]){
               continue;
           }
            
            solution.push_back(nums[j]);
            
            func(nums,j+1,n,solution);
            
            solution.pop_back();
            
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<int>solution;
        
        func(nums,0,n,solution);
        
        return ans;
        
    }
};

// 1 1 1 2 2
    
    
