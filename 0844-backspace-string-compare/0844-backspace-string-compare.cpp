class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int m = s.length();
        int n = t.length();
        string res1 = "";
        string res2 = "";
        for(int i=0;i<m;i++){
            if(s[i]=='#'){
                if(res1.length()){
                    res1.pop_back();
                }
            }
            else{
                res1 += s[i];
            }
        }
        for(int i=0;i<n;i++){
            if(t[i]=='#'){
                if(res2.length()){
                    res2.pop_back();
                }
            }
            else{
                res2 += t[i];
            }
        }
        return res1==res2;
    }
};