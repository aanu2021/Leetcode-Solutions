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
    
    int findPartition(vector<int>&nums,int low,int high){
        int i = low + 1, j = high;
        int pivot = nums[low];
        do{
            
            while(i <= j && nums[i] <= pivot) i++;
            while(i <= j && nums[j] > pivot) j--;
            if(i < j){
                swap(nums[i],nums[j]);
            }
            
        }while(i <= j);
        swap(nums[low],nums[j]);
        return j;
    }
    
    void quicksort(vector<int>&nums,int low,int high){
        if(low < high){
            int partition = findPartition(nums,low,high);
            quicksort(nums,low,partition-1);
            quicksort(nums,partition+1,high);
        }
    }
    
    vector<int>Quick_Sort(vector<int>&nums){
        int n = nums.size();
        quicksort(nums,0,n-1);
        return nums;
    }
    
    void heapify(vector<int>&nums,int i,int n){
        int l = (2*i+1);
        int r = (2*i+2);
        int greatest = i;
        if(l < n && nums[l] > nums[greatest]){
            greatest = l;
        }
        if(r < n && nums[r] > nums[greatest]){
            greatest = r;
        }
        if(greatest != i){
            swap(nums[i],nums[greatest]);
            heapify(nums,greatest,n);
        }
    }
    
    vector<int>Heap_Sort(vector<int>&nums){
        int n = nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // return Merge_Sort(nums);
        // return Quick_Sort(nums);
        return Heap_Sort(nums);
    }
};