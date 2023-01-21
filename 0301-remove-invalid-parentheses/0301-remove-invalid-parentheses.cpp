class Solution {
public:
    
    vector<string>ans;
    set<string>S;
    
    bool isAlphabet(char ch){
        if(ch >= 'a' && ch <= 'z') return true;
        return false;
    }
    
    int getMinOps(string &s){
        int n = s.length();
        int leftBracket = 0;
        int rightBracket = 0;
        for(int i=0;i<n;i++){
            if(isAlphabet(s[i])) continue;
            if(s[i] == '('){
                leftBracket++;
            }
            else{
                if(leftBracket) leftBracket--;
                else            rightBracket++;
            }
        }
        return leftBracket + rightBracket;
    }
    
    void func(string s,int k){
        if(k == 0){
            auto itr = find(ans.begin(),ans.end(),s);
            if(itr == ans.end() && getMinOps(s)==0){
                ans.push_back(s);
            }
            return;
        }
        if(k < 0) return;
        for(int i=0;i<s.length();i++){
            if(isAlphabet(s[i])) continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string temp = left + right;
            if(S.find(temp) == S.end()){
                S.insert(temp);
                func(temp,k-1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int k = getMinOps(s);
        func(s,k);
        return ans;
    }
};