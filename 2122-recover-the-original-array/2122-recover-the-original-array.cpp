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
            
            ans.clear();
            
            multiset<int>ms(nums.begin(),nums.end());
            
            while(!ms.empty()){
                
                auto itr=ms.begin();
                
                int currval=*itr;
                
                ms.erase(itr);
                
                int reqval=currval+k;
                
                auto itr2=ms.find(reqval);
                
                if(itr2==ms.end()){
                    
                    break;
                    
                }
                
                else{
                    
                    ms.erase(itr2);
                    
                    ans.push_back(currval+k/2);
                    
                }
                
            }
            
            if(ans.size()==n/2){
                return ans;
            }
            
            else{
                continue;
            }
            
        }
        
        return {};
        
    }
};