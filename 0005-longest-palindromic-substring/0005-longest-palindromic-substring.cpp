class Solution {
public:
    
    vector<int>lps(string s){
        int n = s.length();
        s = "#" + s + "*";
        vector<int>p(n+2,0);
        int l=1, r=1;
        for(int i=1;i<=n;i++){
            p[i] = max(0, min(r-i, p[l+(r-i)]));
            while(s[i-p[i]] == s[i+p[i]]){
                p[i]++;
            }
            if(i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }
        return p;
    }
    
    string longestPalindrome(string s) {
        vector<int>a = lps(s);
        int maxLen = 0;
        int startIdx = -1;
        for(int i=0;i<a.size();i++){
            int currLen = (2*a[i]) - 1;
            if(currLen > maxLen){
                maxLen = currLen;
                startIdx = i-a[i];
            }
        }
        string t = "";
        for(int i=0;i<s.length();i++){
            t += "?";
            t += s[i];
        }
        t += "?";
        vector<int>b = lps(t);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }cout<<"\n";
        for(int i=0;i<b.size();i++){
            int currLen = (b[i]/2)*2;
            if(i%2 && currLen > maxLen){
                maxLen = currLen;
                startIdx = (i/2) - (currLen/2);
            }
        }
        cout<<maxLen<<"\n";
        if(maxLen == 0 || startIdx == -1) return "";
        return s.substr(startIdx, maxLen);
    }
};