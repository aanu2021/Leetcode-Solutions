class Solution {
public:
    string removeKdigits(string s, int k) {
        
        stack<char>S;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            while(!S.empty() && S.top() > s[i] && k>0){
                S.pop();
                k--;
            }
            if(S.empty() && s[i]=='0'){
                continue;
            }
            else{
                S.push(s[i]);
            }
        }
        
        while(!S.empty() && k>0){
            S.pop();
            k--;
        }
        
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        
        while(res.length() && res.back()=='0'){
            res.pop_back();
        }
        
        reverse(res.begin(),res.end());
        return res.length() ? res : "0";
        
    }
};