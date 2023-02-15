class Solution {
public:
    
    bool isDigit(char ch){
        if(ch>='0' && ch<='9') return true;
        else return false;
    }
    bool isAlphabet(char ch){
        if(ch>='a' && ch<='z') return true;
        else return false;
    }
    
    string decodeString(string s) {
        int n = s.length();
        stack<string>strs;
        stack<int>values;
        for(int i=0;i<s.length();i++){
            if(isDigit(s[i])){
                int number = 0;
                int j = i;
                while(j<n && isDigit(s[j])){
                    number = (number*10) + (s[j]-'0');
                    j++;
                }
                i = j;
                i--;
                values.push(number);
                continue;
            }
            else if(isAlphabet(s[i])){
                strs.push(string(1,s[i]));
            }
            else if(s[i]=='['){
                strs.push(string(1,s[i]));
            }
            else{
                string temp = "";
                while(!strs.empty() && strs.top() != "["){
                    temp += strs.top(); strs.pop();
                }
                strs.pop();
                int repeat = values.top(); values.pop();
                string curr = "";
                for(int rep=1;rep<=repeat;rep++){
                    curr += temp;
                }
                strs.push(curr);
            }
        }
        
        string ans = "";
        while(!strs.empty()){
            ans += strs.top(); strs.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};