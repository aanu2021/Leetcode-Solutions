class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            int currDiff = arr[i] - arr[i-1];
            if(currDiff != (arr[1]-arr[0])){
                return false;
            }
        }
        return true;
    }
};