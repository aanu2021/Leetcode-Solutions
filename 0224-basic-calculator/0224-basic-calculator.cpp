class Solution {
public:
    
    typedef long long ll;
    
    stack<char>ops;
    stack<ll>values;
    
    bool isoperand(char ch){
        if(ch>='0' && ch<='9') return true;
        else return false;
    }
    
    bool isoperator(char ch){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return true;
        else return false;
    }
    
    int precedence(char ch){
        if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        else return 0;
    }
    
    ll applyop(ll x,ll y,char op){
        if(op=='+') return x+y;
        if(op=='-') return x-y;
        if(op=='*') return x*y;
        if(op=='/') return x/y;
        return 0;
    }
    
    void operation(){
        ll val1 = 0,val2 = 0;
        val1 = values.top();
        values.pop();
        if(!values.empty()){
            val2 = values.top();
            values.pop();
        }
        char op = ops.top();
        ops.pop();
        values.push(applyop(val2,val1,op));
    }
    
    void trim(string &s){
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            res+=s[i];
        }
        s=res;
        res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && i+1<s.length() && isoperator(s[i+1])){
                res+=s[i];
                res+="0";
            }else{
                res+=s[i];
            }
        }
        s=res;
    }
    
    int calculate(string s) {
        
        trim(s);
        
        int n = s.length();
    
        
        // 1 - (-2)  Case Handling 
        
//         for(int i=0;i<n;i++){
//             if(s[i]=='(' && i+1<n && isoperator(s[i+1])){
//                 res+=s[i];
//                 res+="0";
//             }else{
//                 res+=s[i];
//             }
//         }
        
//         // overright the actual string with the modified one 
        
//         s = res;
//         n = s.length();
        
        for(int i=0;i<n;i++){
            
            // Trivial Case : For empty spaces just skip them 
            
            if(s[i]==' '){
                continue;
            }
            
            // For opening brace , just add it as the left boundary of arithmetic operations ( x + y )
            
            else if(s[i]=='('){
                ops.push(s[i]);
            }
            
            // For numeric digits just push them into stack for further operations.
            
            else if(isoperand(s[i])){
                ll val = 0LL;
                int j=i;
                while(j<n && isoperand(s[j])){
                    val = (val*10) + (s[j]-'0');
                    j++;
                }
                values.push(val);
                i=j;
                i--;
            }
            
            // For numeric operators we should take care about their precedence as well 
            
            else if(isoperator(s[i])){
                
                while(!ops.empty() && precedence(s[i])<=precedence(ops.top())){
                    
                    operation();
                    
                }
                
                ops.push(s[i]);
                
            }
            
            // Final Case : When it is the closing brace , just complete the operations till the opening brace 
            
            else{
                
                while(!ops.empty() && ops.top()!='('){
                    
                    operation();
                    
                }
                
                ops.pop();
                
            }
            
        }
        
        while(!ops.empty()){
            
            operation();
            
        }
        
        return values.top();
        
    }
};