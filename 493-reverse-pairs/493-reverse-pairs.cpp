class Solution {
public:
    
    int merge(vector<int>&nums,int low,int mid,int high){
        
        int cnt=0;
        
        for(int i=low,j=mid+1;i<=mid;i++){
            
            while(j<=high && nums[i]/2.0>nums[j]){
                j++;
            }
            
            cnt+=(j-mid-1);
            
        }
        
        sort(nums.begin()+low,nums.begin()+high+1);
        
        return cnt;
        
    }
    
    int mergesort(vector<int>&nums,int low,int high){
        
        int cnt=0;
        
        if(low<high){
            
            int mid=(low+high)/2;
            
            cnt+=mergesort(nums,low,mid);
            cnt+=mergesort(nums,mid+1,high);
            
            cnt+=merge(nums,low,mid,high);
            
        }
        
        return cnt;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        
        return mergesort(nums,0,n-1);
        
    }
};