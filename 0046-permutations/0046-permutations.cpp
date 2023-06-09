class Solution {
public:
    
    vector<vector<int>>answer;
    
    void func(vector<int>&nums,int i,int n,vector<int>&solution,vector<int>&vis){
        
        if(i == n){
            answer.push_back(solution);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(vis[j]) continue;
            
            vis[j] = 1;
            solution.push_back(nums[j]);
            
            func(nums,i+1,n,solution,vis);
            
            solution.pop_back();
            vis[j] = 0;
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>vis(n,0);
        vector<int>solution;
        
        func(nums,0,n,solution,vis);
        
        return answer;
        
    }
};