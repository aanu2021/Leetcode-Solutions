class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int>op1(n,0);
        vector<int>op2(n,0);
        
        for(int i=0;i<n;++i){
            
            int curr=nums[i];
            
            if(curr==0){
                
                op1[i]=0;
                op2[i]=0;
                continue;
                
            }
            
            else{
                
                while(curr>0){
                    
                    if(curr%2!=0){
                        curr--;
                        op1[i]++;
                    }
                    
                    else{
                        curr/=2;
                        op2[i]++;
                    }
                    
                }
                
            }
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=op1[i];
        }
        
        int curr=0;
        
        for(int i=0;i<n;i++){
            curr=max(curr,op2[i]);
        }
        
        return ans+curr;
        
    }
};