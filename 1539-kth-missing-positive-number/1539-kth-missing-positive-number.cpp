class Solution {
public:
    int findKthPositive2(vector<int>& arr, int k) {
        int n = arr.size();
        if(arr[0] > k) return k;
        else k -= (arr[0]-1);
        for(int i=0;i<n-1;i++){
            int currDiff = arr[i+1] - arr[i] - 1;
            if(k > currDiff){
                k -= currDiff;
            }
            else{
                return arr[i] + k;
            }
        }
        return arr[n-1] + k;
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(arr[0] > k) return k;
        int ans = -1;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            int currDiff = arr[mid] - mid - 1;
            if(currDiff < k){
                ans = arr[mid] + (k - currDiff);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    
};