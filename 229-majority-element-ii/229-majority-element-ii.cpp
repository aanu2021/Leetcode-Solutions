class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
       int n=nums.size();
        
        int cnt1=1,cnt2=0,val1=nums[0],val2=nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]==val1){
                cnt1++;
            }
            
            else if(nums[i]==val2){
                cnt2++;
            }
            
            else{
                
                if(cnt1==0){
                    cnt1=1;
                    val1=nums[i];
                }
                
                else if(cnt2==0){
                    cnt2=1;
                    val2=nums[i];
                }
                
                else{
                    cnt1--;
                    cnt2--;
                }
                
            }
            
        }
        
       
        cnt1=0,cnt2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==val1){
                cnt1++;
            }
            if(nums[i]==val2){
                cnt2++;
            }
        }
        
        vector<int>ans;
        
        if(cnt1>(n/3)){
            ans.push_back(val1);
        }
        
        if(cnt2>(n/3) && val1!=val2){
            ans.push_back(val2);
        }
        
        return ans;
        
    }
};