class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if(arr[0] > k) return k;
        else k -= max(0,arr[0]-1);
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
};


    
    