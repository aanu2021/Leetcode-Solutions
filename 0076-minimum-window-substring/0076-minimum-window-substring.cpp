class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        int count = 0;
        
        unordered_map<char,int>freq;
        for(int i=0;i<m;i++){
            if(freq[t[i]] == 0) count++;
            freq[t[i]]++;
        }
        
        int l = 0, r = 0;
        int startIndex = -1;
        int minLen = n + 1;
        
        while(r < n){
            freq[s[r]]--;
            if(freq[s[r]] == 0) count--;
            while(l <= r && count == 0){
                int currLen = (r-l+1);
                if(currLen < minLen){
                    minLen = currLen;
                    startIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) count++;
                l++;
            }
            r++;
        }
        
        return minLen == n+1 ? "" : s.substr(startIndex, minLen);
    }
};