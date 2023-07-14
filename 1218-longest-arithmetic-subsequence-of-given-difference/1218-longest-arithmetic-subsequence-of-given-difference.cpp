class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i]-d]);
            maxLen = max(maxLen, mp[arr[i]]);
        }
        return maxLen;
    }
};