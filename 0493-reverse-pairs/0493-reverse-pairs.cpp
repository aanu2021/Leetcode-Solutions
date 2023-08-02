class Solution {
public:
    
    int merge(vector<int>&nums,vector<int>&temp,int low,int mid,int high){
        
        int cnt = 0;
        int j = mid+1;
        
        for(int i=low;i<=mid;i++){
            while(j<=high && (nums[i]/2.0) > nums[j]){
                j++;
            }
            cnt += (j-mid-1);
        }
        
        int i = low;
        j = mid+1;
        int idx = low;
        
        while(i<=mid && j<=high){
            if(nums[i] <= nums[j]){
                temp[idx++] = nums[i++];
            }
            else{
                temp[idx++] = nums[j++];
            }
        }
        
        while(i<=mid){
            temp[idx++] = nums[i++];
        }
        
        while(j<=high){
            temp[idx++] = nums[j++];
        }
        
        for(int index=low;index<=high;index++){
            nums[index] = temp[index];
        }
        
        return cnt;
    }
    
    int mergesort(vector<int>&nums,vector<int>&temp,int low,int high){
        int cnt = 0;
        if(low < high){
            int mid = (low + high)/2;
            cnt += mergesort(nums,temp,low,mid);
            cnt += mergesort(nums,temp,mid+1,high);
            cnt += merge(nums,temp,low,mid,high);
        }
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
        int ans = mergesort(nums,temp,0,n-1);
        return ans;
    }
};