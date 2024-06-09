class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char>S;
        for(int i=0;i<n;i++){
            if(s[i] >= '0' && s[i] <= '9'){
                if(!S.empty()){
                    S.pop();
                }
            }
            else{
                S.push(s[i]);
            }
        }
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};