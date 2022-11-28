class Solution {
public:
    
    int solve(string s){
        
        int n = s.length();
        string temp = s;
        reverse(temp.begin(),temp.end());
        s+="*";
        s+=temp;
        n = s.length();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            while(len>0 && s[len]!=s[i]){
                len = lps[len-1];
            }
            if(s[i]==s[len]){
                len++;
            }
            lps[i] = len;
        }
        return lps[n-1];
        
    }
    
    string shortestPalindrome(string s) {
        
        int n = s.length();
        int ans = solve(s);
        int req = (n-ans);
        int i = n-1;
        string res = "";
        while(req>0){
            res+=s[i--];
            req--;
        }
        res+=s;
        return res;
        
    }
};