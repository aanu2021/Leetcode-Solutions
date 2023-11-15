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

/*

1. ans -> store the longest sequence we have
2. ans = (ans + count[num], num)
3. 1 3 3 3 3 3 => 1 2 3 3 3
4. 1 4 4 8 8 8 => 1 2 3 8 8 8 => 1 2 3 4 5 6   

*/