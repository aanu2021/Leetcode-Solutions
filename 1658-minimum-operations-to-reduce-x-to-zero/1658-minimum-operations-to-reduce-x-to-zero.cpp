class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum==x){
            return n;
        }
        
        int target=sum-x;
        
        int maxLen=-1;
        
        int l=0,r=0;
        
        int currsum=0;
        
        while(l<n && r<n){
            
            currsum+=nums[r];
            
            while(l<=r && currsum>target){
                
                currsum-=nums[l];
                l++;
                
            }
            
            if(currsum==target){
                maxLen=max(maxLen,r-l+1);
            }
            
            r++;
            
            
        }
        
        if(maxLen==-1){
            return -1;
        }else{
            return n-maxLen;
        }
        
    }
};