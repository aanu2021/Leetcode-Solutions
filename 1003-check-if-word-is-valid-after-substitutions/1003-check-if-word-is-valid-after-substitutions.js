class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>S;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='b'){
                S.push(s[i]);
            }
            else{
                if(S.size() < 2) return false;
                char ch2 = S.top(); S.pop();
                char ch1 = S.top(); S.pop();
                if(ch2=='b' && ch1=='a'){
                    continue;
                }
                else{
                    S.push(ch1);
                    S.push(ch2);
                    S.push(s[i]);
                }
            }
        }
        return S.size()==0;
    }
};

// abcababcc