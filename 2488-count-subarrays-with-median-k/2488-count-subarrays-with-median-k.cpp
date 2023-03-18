class Solution {
public:
    int countSubarrays(vector<int>& arr, int m) {
        int n = arr.size();
        unordered_map<int,int>freq;
        freq[0] = 1;
        int sum = 0;
        int ans = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(arr[i] < m) sum--;
            else if(arr[i] > m) sum++;
            else flag = true;
            if(flag){
                ans += freq[sum];
                ans += freq[sum-1];
            }
            else{
                freq[sum]++;
            }
        }
        return ans;
    }
};