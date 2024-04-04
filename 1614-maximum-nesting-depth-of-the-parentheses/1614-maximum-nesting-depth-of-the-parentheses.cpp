class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int cnt = 0, mx = 0;
        for(char ch : s){
            if(ch == '(') cnt++;
            else if(ch == ')') cnt--;
            mx = max(mx, cnt);
        }
        return mx;
    }
};