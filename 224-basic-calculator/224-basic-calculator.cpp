class Solution {
public:
    
    typedef long long ll;
    
    bool isOperator(char ch){
        
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            return true;
        }
        
        else{
            return false;
        }
        
    }
    
    bool isOperand(char ch){
        
        if(ch>='0' && ch<='9'){
            return true;
        }
        
        else{
            return false;
        }
        
    }
    
    int precedence(char ch){
        
        if(ch=='*' || ch=='/'){
            return 2;
        }
        
        else if(ch=='+' || ch=='-'){
            return 1;
        }
        
        else{
            return 0;
        }
        
    }
    
    
    ll applyop(ll a,ll b,char op){
        
        if(op=='+'){
            return (a+b);
        }
        
        if(op=='-'){
            return (a-b);
        }
        
        if(op=='*'){
            return (a*b);
        }
        
        if(op=='/'){
            return (a/b);
        }
        
        else{
            return -1;
        }
        
    }
    
    int calculate(string s) {
        
        string res="";
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='(' && i+1< s.length() && isOperator(s[i+1])==true){
                
                res+="(";
                res+="0";
                
            }
            
            else{
                
                res+=s[i];
                
            }
            
        }
        
        s=res;
        
        int n=s.length();
        
        stack<char>ops;
        stack<ll>values;
        
        for(ll i=0;i<n;i++){
            
            if(s[i]==' '){
                continue;
            }
            
            else if(s[i]=='('){
                ops.push(s[i]);
            }
            
            else if(isOperand(s[i])==true){
                
                ll value=0;
                
                while(i<n && isOperand(s[i])==true){
                    
                    value=(value*10)+s[i]-'0';
                    i++;
                    
                }
                
                i--;
                
                values.push(value);
                
            }
            
            else if(isOperator(s[i])==true){
                
                while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){
                    
                    ll value1=0,value2=0;
                    
                    char op=ops.top();
                    ops.pop();
                    
                    value1=values.top();
                    values.pop();
                    
                    if(!values.empty()){
                        value2=values.top();
                        values.pop();
                    }
                    
                    values.push(applyop(value2,value1,op));
                    
                }
                
                ops.push(s[i]);
                
            }
            
            
            else if(s[i]==')'){
                
                while(!ops.empty() && ops.top()!='('){
                    
                    ll value1=0,value2=0;
                    
                    char op=ops.top();
                    ops.pop();
                    
                    value1=values.top();
                    values.pop();
                    
                    if(!values.empty()){
                        value2=values.top();
                        values.pop();
                    }
                    
                    values.push(applyop(value2,value1,op));
                    
                }
                
                ops.pop();
                
            }
            
        }
        
        
        while(!ops.empty()){
            
             ll value1=0,value2=0;
                    
                    char op=ops.top();
                    ops.pop();
                    
                    value1=values.top();
                    values.pop();
                    
                    if(!values.empty()){
                        value2=values.top();
                        values.pop();
                    }
                    
                    values.push(applyop(value2,value1,op));
            
        }
        
        return values.top();
        
    }
};