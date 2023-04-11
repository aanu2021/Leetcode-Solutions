class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        stack<char>S;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                S.pop();
            }else{
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