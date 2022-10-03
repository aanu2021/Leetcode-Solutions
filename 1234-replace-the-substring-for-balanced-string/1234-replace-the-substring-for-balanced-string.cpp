class Solution {
public:
    int balancedString(string s) {

        int n = s.length();
        
        int k = (n/4);
        
        int minLen = n+1;
        
        unordered_map<char,int>count;
        
        int maxval = 0;
        
        for(char ch:s){
            count[ch]++;
            maxval=max(maxval,count[ch]);
        }
        
        if(maxval==k) return 0;
        
        int l=0,r=0;
        
        while(l<n && r<n){
            
            count[s[r]]--;
            
            while(l<=r && count['Q']<=k && count['W']<=k && count['E']<=k && count['R']<=k){
                
                minLen = min(minLen,r-l+1);
                
                count[s[l]]++;
                
                l++;
                
            }
            
            r++;
            
        }
        
        return minLen;
        
    }
};

