class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n=nums.size();
        
        int prod=1;
        
        int flag=0;
        
        for(int i:nums){
            if(i==0){
                flag++;
            }else{
                prod*=i;   
            }
        }
        
        for(int i=0;i<n;++i){
            
            if(flag>1){
                nums[i]=0;
            }
            
            else if(flag==0){
                nums[i]=(prod/nums[i]);
            }
            
            else{
                
                if(nums[i]==0){
                    nums[i]=prod;
                }
                
                else{
                    nums[i]=0;
                }
                
            }
            
        }
        
        return nums;
        
    }
};