class Solution {
public:
    
    void func(vector<int>nums,int start,int end,vector<vector<int>>&result){
        
        if(start==end-1){
            result.push_back(nums);
            return;
        }
        
        for(int i=start;i<end;i++){
            
            if(i!=start && nums[i]==nums[start]){
                continue;
            }
                
                swap(nums[i],nums[start]);
                
                func(nums,start+1,end,result);
                
               // swap(nums[i],nums[start]);
                
            
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>result;
        
        func(nums,0,n,result);
        
        return result;
        
    }
};