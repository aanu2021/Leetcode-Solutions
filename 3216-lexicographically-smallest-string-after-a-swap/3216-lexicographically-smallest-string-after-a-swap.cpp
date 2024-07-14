class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i=0;i<n-1;i++){
            int x = (int)(s[i]-'0');
            int y = (int)(s[i+1]-'0');
            if(x%2 == y%2){
                if(x > y){
                    swap(s[i], s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};