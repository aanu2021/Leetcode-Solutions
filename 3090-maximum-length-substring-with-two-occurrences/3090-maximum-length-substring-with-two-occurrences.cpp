class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLen = 0, l = 0, r = 0, count = 0;
        unordered_map<char,int>freq;
        while(r < n){
            freq[s[r]]++;
            if(freq[s[r]] > 2) count++;
            while(l <= r && count > 0){
                freq[s[l]]--;
                if(freq[s[l]] == 2) count--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};