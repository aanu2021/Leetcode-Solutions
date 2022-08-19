class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int>freq;
        
        for(int i:nums){
            
            freq[i]++;
            
        }
        
        int count=0,p=0;
        
        for(int i=0;i<n;++i){
            
            if(freq[nums[i]]>0){
                
                int curr=nums[i];
                
                while(freq[curr]>0 && count<k){
                    
                    freq[curr]--;
                    
                    count++;
                    
                    curr++;
                    
                }
                
                if(count==k){
                    
                    p++;
                    count=0;
                    
                }
                
                else{
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return (n==(k*p));
        
    }
};