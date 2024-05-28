class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n = s.length();
        int currSum = 0;
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            currSum += abs(s[r] - t[r]);
            while(l <= r && currSum > k){
                currSum -= abs(s[l] - t[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};