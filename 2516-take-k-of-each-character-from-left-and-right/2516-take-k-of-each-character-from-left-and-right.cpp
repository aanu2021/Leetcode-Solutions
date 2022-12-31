class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int maxLen = -1;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        if(freq[0] < k || freq[1] < k || freq[2] < k) return -1;
        int l=0,r=0;
        while(r<n){
            freq[s[r]-'a']--;
            while(l<=r && freq[s[r]-'a'] < k){
                freq[s[l]-'a']++;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return n - maxLen;
    }
};