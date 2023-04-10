class Solution {
public:
    
    bool isMatch(char ch1,char ch2){
        
        if(ch1=='(' && ch2==')'){
            return true;
        }
        
        if(ch1=='{' && ch2=='}'){
            return true;
        }
        
        if(ch1=='[' && ch2==']'){
            return true;
        }
        
        return false;
        
    }
    
    bool isValid(string s) {
        
        int n=s.length();
        
        stack<char>st;
        
        for(int i=0;i<n;++i){
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                
                st.push(s[i]);
                
            }
            
            else{
                
                if(st.empty()){
                    return false;
                }
                
                if(!st.empty() && isMatch(st.top(),s[i])==false){
                    
                    return false;
                    
                }
                
                st.pop();
                
            }
            
        }
        
        return st.empty();
        
    }
};