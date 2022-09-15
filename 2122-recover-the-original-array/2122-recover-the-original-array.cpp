class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;++i){
            
            int k=(nums[i]-nums[0]);
            
            if(k==0 || k%2){
                continue;
            }
            
            multiset<int>ms(nums.begin(),nums.end());
            
            while(!ms.empty()){
                
                auto itr=ms.begin();
                
                int val=*itr;
                
                int req_val=(val+k);
                
                ms.erase(itr);
                
                if(ms.find(req_val)==ms.end()){
                    
                    break;
                    
                }
                
                else{
                    
                    ms.erase(ms.lower_bound(req_val));
                    
                    ans.push_back(val+k/2);
                    
                }
                
            }
            
            if(ans.size()==n/2){
                
                return ans;
                
            }
            
            else{
                
                ans.clear();
                continue;
                
            }
            
        }
        
        return ans;
        
    }
};