class Solution {
public:
    
    typedef long long ll;
    
    bool isChar(char ch){
        return (ch>='a' && ch<='z');
    }
    bool isDigit(char ch){
        return (ch>='0' && ch<='9');
    }
    
    string decodeAtIndex(string s, int k) {
        
        int n = s.length();
        ll size = 0LL;
        
        for(int i=0;i<n;i++){
            if(isDigit(s[i])){
                size *= (ll)(s[i]-'0');
            }
            else{
                size++;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            k %= size;
            if(k==0 && isChar(s[i])){
                return string(1,s[i]);
            }
            if(isChar(s[i])){
                size--;
            }
            else{
                size /= (ll)(s[i]-'0');
            }
        }
        
        return "";
        
    }
};

/*


ha22     k = 5
hahaha   

leet2code3   k = 3
  .
    
Actual Length = 36 -> 12 -> 11 -> 10 -> 9 -> 8 -> 4 -> 3
    
leetleetcodeleetleetcodeleetleetcode   

abc2de3fg2      k = 0      size = 1
p   
abcabcdeabcabcdeabcabcdefgabcabcdeabcabcdeabcabcdefg


*/

