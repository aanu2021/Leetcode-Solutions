class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int>count(n+1, 0);
        for(int i=0;i<n;i++){
            count[min(arr[i],n)]++;
        }
        int ans = 1;
        for(int num=2;num<=n;num++){
            ans = min(ans + count[num], num);
        }
        return ans;
    }
};

 