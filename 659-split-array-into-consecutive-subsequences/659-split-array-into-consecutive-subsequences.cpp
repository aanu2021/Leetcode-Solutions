class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int>available;
        
        unordered_map<int,int>vacancy;
        
        for(int i:nums){
            
            available[i]++;
            
        }
        
        
        for(int i=0;i<n;++i){
            
            if(available[nums[i]]<=0){
                
                continue;
                
            }
            
            else if(vacancy[nums[i]]>0){
                
                vacancy[nums[i]]--;
                
                available[nums[i]]--;
                
                vacancy[nums[i]+1]++;
                
            }
            
            else if(available[nums[i]]>0 && available[nums[i]+1]>0 && available[nums[i]+2]>0){
                
                available[nums[i]]--;
                available[nums[i]+1]--;
                available[nums[i]+2]--;
                
                vacancy[nums[i]+3]++;
                
            }
            
            else{
                
                return false;
                
            }
            
        }
        
        return true;
        
    }
};