class Solution {
public:
    
    unordered_map<char,int>count;
    
    bool isValid(int k){
        
        if(count['Q']<=k && count['W']<=k && count['E']<=k && count['R']<=k) return true;
        
        return false;
        
    }
    
    int balancedString(string s) {
        
        int n=s.length();
        
        int k = (n/4);
        
        int minLen = n+1;
        
        int maxval = 0;
        
        for(char ch:s){
            count[ch]++;
            maxval=max(maxval,count[ch]);
        }
        
        if(maxval==k) return 0;
        
        int l=0,r=0;
        
        while(r<n){
            
            count[s[r]]--;
            
            while(l<=r && isValid(k)){
                
                minLen = min(minLen,r-l+1);
                
                count[s[l]]++;
                
                l++;
                
            }
            
            r++;
            
        }
        
        return minLen;
        
    }
};