class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        stack<char>S;
        for(int i=0;i<n;i++){
            if(!S.empty() && S.top()==s[i]){
                S.pop();
            }
            else{
                S.push(s[i]);
            }
        }
        s.clear();
        while(!S.empty()){
            s += S.top(); S.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};