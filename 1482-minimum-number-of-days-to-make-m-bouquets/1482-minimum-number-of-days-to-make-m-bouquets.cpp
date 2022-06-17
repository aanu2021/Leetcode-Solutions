class Solution {
public:
    
    bool isPossible(vector<int>&nums,int mid,int m,int k){
        
        int n=nums.size();
        
        vector<int>v(n,0);
        
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                v[i]=1;
            }
        }
        
        int currsum=0;
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            
            if(v[i]==0){
                continue;
            }
            
            int j=i;
            
            currsum=0;
            
            while(j<n && v[j]==1 && currsum<k){
                currsum++;
                j++;
            }
            
            if(currsum==k){
                
                cnt++;
                
            }
            
            i=j;
            i--;
            
        }
        
        return cnt>=m;
        
    }
    
    int minDays(vector<int>& nums, int m, int k) {
        
        int n=nums.size();
        
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(isPossible(nums,mid,m,k)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};