class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m > n) return false;
        int j = 0;
        for(int i=0;i<n && j<m;i++){
            if(s[j]==t[i]){
                j++;
            }
            else{
                continue;
            }
        }
        return j==m;
    }
};