/*

T.C : O(N)
S.C : O(26) == O(1)

*/

class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        unordered_map<int,int>freq;
        int count = 0;
        for(int i=0;i<m;i++){
            if(freq[t[i]] == 0) count++;
            freq[t[i]]++;
        }
        
        int l = 0,r = 0;
        int minLen = n+1;
        int startIdx = -1;
        
        while(r<n){
            freq[s[r]]--;
            if(freq[s[r]] == 0) count--;
            while(l <= r && count == 0){
                int currLen = (r-l+1);
                if(currLen < minLen){
                    minLen = currLen;
                    startIdx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] == 1) count++;
                l++;
            }
            r++;
        }
        
        return minLen==n+1 ? "" : s.substr(startIdx,minLen);
    }
};

/*

ADOBECODEBANC

ABC

mp['A'] = 0
mp['B'] = -1
mp['C'] = 0
mp['D'] = -2
mp['E'] = -2    
mp['O'] = -2    
    
count = 0
    
l = 1
r = 10
    
minLen = 6    
    
*/    