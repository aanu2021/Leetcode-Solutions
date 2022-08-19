class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
       int n=nums.size();
        
        unordered_map<int,int>available_map;
        
        unordered_map<int,int>want_map;
        
        for(int i=0;i<n;++i){
            available_map[nums[i]]++;
        }
        
        for(int i=0;i<n;++i){
            
            if(available_map[nums[i]]<=0){
                continue;
            }
            
            else if(want_map[nums[i]]>0){
                
                available_map[nums[i]]--;
                
                want_map[nums[i]]--;
                
                want_map[nums[i]+1]++;
                
            }
            
            else if(available_map[nums[i]]>0 && available_map[nums[i]+1]>0 && available_map[nums[i]+2]>0){
                
                 available_map[nums[i]]--;
                 available_map[nums[i]+1]--;
                 available_map[nums[i]+2]--;
                
                want_map[nums[i]+3]++;
                
            }
            
            else{
                
                return false;
                
            }
            
        }
        
        return true;
        
    }
};