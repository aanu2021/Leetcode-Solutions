class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        int n=s.length();
        
        int l=0,r=0,count=0;
        
        int maxLen=0;
        
        while(r<n){
            
            if(s[r]=='F'){
                count++;
            }
            
            while(l<=r && count>k){
                
                if(s[l]=='F'){
                    count--;
                }
                
                l++;
                
            }
            
            maxLen=max(maxLen,r-l+1);
            
            r++;
            
        }
        
        
        l=0,r=0,count=0;
        
        while(r<n){
            
            if(s[r]=='T'){
                count++;
            }
            
            while(l<=r && count>k){
                
                if(s[l]=='T'){
                    count--;
                }
                
                l++;
                
            }
            
            maxLen=max(maxLen,r-l+1);
            
            r++;
            
        }
        
        return maxLen;
        
    }
};