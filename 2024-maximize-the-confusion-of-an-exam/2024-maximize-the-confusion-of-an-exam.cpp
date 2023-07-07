class Solution {
public:
    
    int func(string &s,int n,int k,char target){
        
        int maxLen = 0;
        int l = 0,r = 0,cnt = 0;
        
        while(r < n){
            if(s[r] != target) cnt++;
            while(l <= r && cnt > k){
                if(s[l] != target) cnt--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        
        return maxLen;
        
    }
    
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.length();
        int maxLen = func(s,n,k,'T');
        maxLen = max(maxLen, func(s,n,k,'F'));
        return maxLen;
    }
};