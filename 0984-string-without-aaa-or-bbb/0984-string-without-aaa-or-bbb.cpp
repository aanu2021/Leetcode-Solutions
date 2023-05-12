class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        int n = a + b;
        for(int i=0;i<n;i++){
            int L = s.length();
            if(a > b){
                if(L >= 2 && s[L-2]=='a' && s[L-1]=='a'){
                    s += "b";
                    b--;
                }
                else{
                    s += "a";
                    a--;
                }
            }
            else{
                if(L >= 2 && s[L-2]=='b' && s[L-1]=='b'){
                    s += "a";
                    a--;
                }
                else{
                    s += "b";
                    b--;
                }
            }
        }
        return s;
    }
};