class NumArray {
public:
    
    int arr[30005];
    int bucket[30005];
    int root;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        
        memset(arr,0,sizeof(arr));
        memset(bucket,0,sizeof(bucket));
        
        for(int i=0;i<n;i++){
            arr[i] = nums[i];
        }
        
        root = sqrt(n);
        for(int i=0;i<n;i++){
            bucket[i/root] += arr[i];
        }
       
    }
    
    void update(int index, int val) {
        
        int buck = (index/root);
        bucket[buck] -= arr[index];
        arr[index] = val;
        bucket[buck] += arr[index];

    }
    
    int sumRange(int left, int right) {
        
        int currSum = 0;
        
        for(int i=left;i<=right;i++){
            if(i%root==0 && i+root-1 <= right){
                currSum += bucket[i/root];
                i = i + root - 1;
            }
            else{
                currSum += arr[i];
            }
        }
        
        return currSum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */