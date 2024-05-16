class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.length();
        if(n == 1) return "";
        bool flag = false;
        for(int i=0;i<n/2;i++){
            if(n%2 && i == (n/2)) continue;
            if(s[i] != 'a'){
                s[i] = 'a';
                flag = true;
                break;
            }
        }
        if(!flag){
            s[n-1] = 'b';
        }
        return s;
    }
};