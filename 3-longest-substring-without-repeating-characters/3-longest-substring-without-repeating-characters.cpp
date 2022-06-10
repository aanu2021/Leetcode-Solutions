class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen=0;
        
        int n=s.length();
        
        int diff=0;
        
        map<char,int>mp;
        
        int l=0,r=0;
        
        while(l<n && r<n){
            
            mp[s[r]]++;
            
            if(mp[s[r]]>1){
                diff++;
            }
            
            while(diff>0){
                
                int val=mp[s[l]];
                
                mp[s[l]]--;
                
                if(val>1 && mp[s[l]]<=1){
                    diff--;
                }
                
                l++;
                
            }
            
            maxLen=max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};