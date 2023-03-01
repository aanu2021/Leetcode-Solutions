class Solution {
public:
    
    void merge(vector<int>&nums,int low,int mid,int high,vector<int>&auxArr){
        int i = low, j = mid + 1;
        int k = low;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                auxArr[k++] = nums[i++];
            }
            else{
                auxArr[k++] = nums[j++];
            }
        }
        while(i <= mid){
            auxArr[k++] = nums[i++];
        }
        while(j <= high){
            auxArr[k++] = nums[j++];
        }
        for(int idx=low;idx<=high;idx++){
            nums[idx] = auxArr[idx];
        }
    }
    
    void mergesort(vector<int>&nums,int low,int high,vector<int>&auxArr){
        if(low < high){
            int mid = (low + high)/2;
            mergesort(nums,low,mid,auxArr);
            mergesort(nums,mid+1,high,auxArr);
            merge(nums,low,mid,high,auxArr);
        }
    }
        
    vector<int>Merge_Sort(vector<int>&nums){
        int n = nums.size();
        vector<int>auxArr(n,-1);
        mergesort(nums,0,n-1,auxArr);
        return nums;
    }    
    
    vector<int> sortArray(vector<int>& nums) {
        return Merge_Sort(nums);
    }
};