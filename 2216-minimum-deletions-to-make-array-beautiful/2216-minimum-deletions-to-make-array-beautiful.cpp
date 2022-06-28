class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int n=nums.size();
        
        int cnt=0;
        
        int j=0;
        
        if(n==1){
            return 1;
        }
        
        if(n==2){
            if(nums[0]!=nums[1]){
                return 0;
            }else{
                return 2;
            }
        }
        
        int ans=n;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1] && j%2==0){
                cnt++;
            }else{
                j++;
            }
        }
        
        if((n-cnt)%2==0){
            return cnt;
        }else{
            return cnt+1;
        }
        
    }
};