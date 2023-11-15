class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        for(int i=1;i<n;i++){
            if(arr[i] == arr[i-1]) continue;
            if((arr[i]-arr[i-1]) == 1) continue;
            int req = arr[i-1] + 1;
            arr[i] = req;
        }
        int MAX = arr[n-1];
        return MAX;
    }
};

// 1 1 1 3 3 4 4 4 7 7
// 1 1 1 2 3 4 4 4 5 6  