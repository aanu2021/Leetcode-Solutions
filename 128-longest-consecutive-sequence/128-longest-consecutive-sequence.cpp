class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int maxLen=0;
        
        for(int i=0;i<n;i++){
            
            int j=i+1;
            
            int prev=nums[i];
            
            int currLen=1;
            
            while(j<n){
                
                if(nums[j]==prev){
                    j++;
                    continue;
                }else if(nums[j]==prev+1){
                    currLen++;
                    prev=nums[j];
                    j++;
                    continue;
                }else{
                    break;
                }
                
            }
            
            maxLen=max(maxLen,currLen);
            
            i=j;
            i--;
            
        }
        
        return maxLen;
        
    }
};