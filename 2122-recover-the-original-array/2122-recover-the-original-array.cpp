class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        // 2 4 6 8 10 12
        
        for(int i=1;i<n;++i){
            
            int k=nums[i]-nums[0];
            
            // k = 2
            
            if(k==0 || k%2){
                continue;
            }
            
            vector<int>ans;
            
            unordered_map<int,int>freq;
            
            for(int ele:nums){
                freq[ele]++;
            }
            
            for(int j=0;j<n;++j){
                
                if(freq[nums[j]]==0){
                    continue;
                }
                
                if(freq[nums[j]]>0 && freq[k+nums[j]]>0){
                    
                    ans.push_back(nums[j]+(k/2));
                    
                    freq[nums[j]]--;
                    freq[k+nums[j]]--;
                    
                }
                
                else{
                    
                    break;
                    
                }
                
            }
            
            if(ans.size()==n/2){
                
                return ans;
                
            }
            
        }
        
        return {};
        
    }
};