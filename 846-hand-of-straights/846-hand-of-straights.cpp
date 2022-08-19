class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int count=0;
        
        int p=0;
        
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int>freq;
        
        for(int i:nums){
            
            freq[i]++;
            
        }
        
        for(int i=0;i<n;++i){
            
            if(freq[nums[i]]>0){
                
                int curr=nums[i];
                
                while(freq[curr]>0 && count<k){
                    
                    freq[curr]--;
                    
                    count++;
                    
                    curr++;
                    
                }
                
                if(count==k){
                    
                    count=0;
                    p++;
                    
                }
                
                else{
                    
                    return false;
                    
                }
                
            }
            
        }
        
        return (n==(k*p));
        
    }
};