class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char>st;
    
    for(int i=0;i<s.length();i++){
        
        
        
         if(s[i]=='('){
             st.push(s[i]);
         }
         
         else if(s[i]>='a' && s[i]<='z'){
             st.push(s[i]);
         }
         
         else if(s[i]==')'){
             string temp="";
             while(!st.empty() && st.top()!='('){
                 temp+=st.top();
                 st.pop();
             }
             st.pop();
             
             for(int i=0;i<temp.length();i++){
                 st.push(temp[i]);
             }
         }
    }
    
    string res="";
    
    
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
        
        return res;
    
    }
};