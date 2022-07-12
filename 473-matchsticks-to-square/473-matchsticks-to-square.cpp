class Solution {
public:
    
    // Brute Force Time Complexity : O(4^N) //
    
    bool func(vector<int>&nums,int i,vector<int>&sides){
        
        if(i==nums.size()){
            
            if(sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0){
                return true;
            }else{
                return false;
            }
            
        }
        
        for(int j=0;j<4;++j){
            
            if(sides[j]<nums[i]){
                continue;
            }
            
            sides[j]-=nums[i];
            
            if(func(nums,i+1,sides)==true){
                
                return true;
                
            }
            
            sides[j]+=nums[i];
            
        }
        
        return false;
        
    }
    
    bool makesquare(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.rbegin(),nums.rend());
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int target=(sum/4);
        
        if(sum%4!=0){
            return false;
        }
        
        vector<int>sides(4,target);
        
        return func(nums,0,sides);
        
    }
};