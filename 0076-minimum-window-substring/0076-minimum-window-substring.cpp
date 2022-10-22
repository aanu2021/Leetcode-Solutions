class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        
        int m = t.length();
        
        int minLen = n+1;
        
        int count = 0;
        
        unordered_map<char,int>mp;
        
        for(int i=0;i<m;i++){
            if(mp[t[i]]==0) count++;
            mp[t[i]]++;
        }
        
        int startIdx = -1;
        
        int l = 0 , r = 0;
        
        while(l<n && r<n){
            
            mp[s[r]]--;
            
            if(mp[s[r]]==0) count--;
            
            while(l<=r && count==0){
                
                int currLen = (r-l+1);
                
                if(currLen < minLen){
                    minLen = currLen;
                    startIdx = l;
                }
                
                mp[s[l]]++;
                
                if(mp[s[l]]==1) count++;
                
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