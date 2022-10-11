class Solution {
public:
    
    int func(string str){
        
        string temp = str;
        
        temp += '?';
        
        reverse(str.begin(),str.end());
        
        temp+=str;
        
        int n = temp.length();
        
        vector<int>lps(n,0);
        
        for(int i=1;i<n;i++){
            
            int len = lps[i-1];
            
            while(len>0 && temp[i]!=temp[len]){
                
                len = lps[len-1];
                
            }
            
            if(temp[i]==temp[len]){
                
                len++;
                
            }
            
            lps[i] = len;
            
        }
        
        return lps[n-1];
        
    }
    
    string shortestPalindrome(string s) {
        
        int n = s.length();
        
        int longest_pref_pal = func(s);
        
        int req = (n-longest_pref_pal);
        
        string res="";
        
        for(int i=n-1;i>=0 && req>0;i--){
            
            res+=s[i];
            
            req--;
            
        }
        
        res+=s;
        
        return res;
        
    }
};