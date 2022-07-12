class Solution {
public:
    
    int merge(vector<int>&nums,int low,int mid,int high){
        
        int ans=0;
        
        int j=mid+1;
        
        for(int i=low;i<=mid;i++){
            
            while(j<=high && (nums[i]/2.0)>nums[j]){
                
                j++;
                
            }
            
            ans+=(j-mid-1);
            
        }
        
        sort(nums.begin()+low,nums.begin()+high+1);
        
//         for(int i=low;i<=high;++i){
//             cout<<nums[i]<<" ";
//         }cout<<"\n";
        
//         cout<<ans<<"\n";
        
        return ans;
        
    }
    
    int mergesort(vector<int>&nums,int low,int high){
        
        int ans=0;
        
        if(low<high){
            
            int mid=(low+high)/2;
            
            ans+=mergesort(nums,low,mid);
            
            ans+=mergesort(nums,mid+1,high);
            
            ans+=merge(nums,low,mid,high);
            
        }
        
        return ans;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int n=nums.size();
        
        return mergesort(nums,0,n-1);
        
    }
};