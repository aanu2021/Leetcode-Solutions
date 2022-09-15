class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>ans;
        
        unordered_map<int,int>freq;
        
        for(int i:nums){
            freq[i]++;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;++i){
            
            if(freq[nums[i]]==0){
                
                continue;
                
            }
            
            if(nums[i]==0 && freq[0]>=2){
                
                freq[0]-=2;
                ans.push_back(0);
                continue;
                
            }
            
            if(nums[i]!=0 && freq[nums[i]]>0 && freq[2*nums[i]]>0){
                
                freq[nums[i]]--;
                freq[2*nums[i]]--;
                ans.push_back(nums[i]);
                continue;
                
            }
            
            else{
                
                return {};
                
            }
            
        }
        
        return ans;
        
    }
};