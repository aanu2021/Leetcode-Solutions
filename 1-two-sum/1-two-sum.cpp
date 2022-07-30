class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mapp;
        
        int n=nums.size();
        
        for(int i=0;i<n;++i){
            
            int required_pair=target-nums[i];
            
            if(mapp.find(required_pair)!=mapp.end()){
                
                return {mapp[required_pair],i};
                
            }
            
            mapp[nums[i]]=i;
            
        }
        
        return {-1,-1};
        
    }
};