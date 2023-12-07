class Solution {
public:
    
    bool isOdd(char ch){
        int num = (int)(ch-'0');
        if(num%2) return true;
        else return false;
    }
    
    string largestOddNumber(string s) {
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(isOdd(s[i])){
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};