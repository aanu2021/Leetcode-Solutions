class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        
        vector<int>tails;
        
        tails.push_back(nums[0]);
        
        for(int i=1;i<n;++i){
            
            if(tails.back()<nums[i]){
                tails.push_back(nums[i]);
                inc[i]=tails.size();
            }
            
            else{
                int idx=lower_bound(tails.begin(),tails.end(),nums[i])-tails.begin();
                tails[idx]=nums[i];
                inc[i]=idx+1;
            }
            
        }
        
        tails.clear();
        
        tails.push_back(nums[n-1]);
        
        for(int i=n-2;i>=0;i--){
            
            if(tails.back()<nums[i]){
                tails.push_back(nums[i]);
                dec[i]=tails.size();
            }
            
            else{
                int idx=lower_bound(tails.begin(),tails.end(),nums[i])-tails.begin();
                tails[idx]=nums[i];
                dec[i]=idx+1;
            }
            
        }
        
        int maxLen = 0;
        
        for(int i=0;i<n;++i){
            
            if(inc[i]>1 && dec[i]>1){
                
                maxLen = max(maxLen,inc[i]+dec[i]-1);
                
            }
            
        }
        
        return n-maxLen;
        
    }
};

/*

     2,1,1,5,6,2,3,1
    
inc: 1,1,1,2,3,2,3,1     
dec: 2,1,1,3,3,2,2,1    

*/
    
    