class Solution {
public:
    
    set<string>S;
    vector<string>ans;
    
    int getMinOps(string s){
        int n = s.length();
        int leftBracket = 0;
        int rightBracket = 0;
        for(int i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            if(s[i]==')'){
                if(leftBracket > 0) leftBracket--;
                else            rightBracket++; 
            }
            else{
                leftBracket++;
            }
        }
        return leftBracket + rightBracket;
    }
    
    void func(string s,int k){
         // cout<<s<<"\n";
        if(k==0){
            auto itr=find(ans.begin(),ans.end(),s);
            if(itr==ans.end() && getMinOps(s)==0){
                ans.push_back(s);
            }
            return;
        }
        if(k < 0) return;
        for(int i=0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z') continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string temp = left + right;
            if(S.find(temp) == S.end()){
                S.insert(temp);
                func(temp,k-1);
            }
            // func(temp,k-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int minOps = getMinOps(s);
        // cout<<minOps<<"\n";
        func(s,minOps);
        return ans;
    }
};