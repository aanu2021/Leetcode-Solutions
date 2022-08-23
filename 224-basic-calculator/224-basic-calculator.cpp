class Solution {
public:
    
    typedef long long ll;
    
    bool isOperand(char ch){
        
        if(ch>='0' && ch<='9'){
            return true;
        }else{
            return false;
        }
        
    }
    
    bool isOperator(char ch){
    
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            return true;
        }else{
            return false;
        }
        
    }
    
    
    ll precedence(char ch){
        
        if(ch=='*' || ch=='/'){
            return 2LL;
        }
        
        else if(ch=='+' || ch=='-'){
            return 1LL;
        }
        
        else{
            return 0LL;
        }
        
    }
    
    
    ll applyop(ll op1,ll op2,char ch){
        
        if(ch=='+'){
            return op1+op2;
        }
        
        if(ch=='-'){
            return op1-op2;
        }
        
        if(ch=='*'){
            return op1*op2;
        }
        
        if(ch=='/'){
            return op1/op2;
        }
        
        return 0LL;
        
    }
    
    int calculate(string s) {
        
        string res="";
        
        for(int i=0;i<s.length();++i){
            
            if(s[i]=='(' && i+1<s.length() && isOperator(s[i+1])){
                
                res+=s[i];
                res+="0";
                
            }
            
            else{
                
              res+=s[i];   
                
            }
            
        }
        
        s=res;
        
        ll n=s.length();
        
        
        stack<char>ops;
        
        stack<ll>values;
        
        
        for(ll i=0;i<n;++i){
            
            if(s[i]==' '){
                
                continue;
                
            }
            
            else if(s[i]=='('){
                
                ops.push(s[i]);
                
            }
            
            else if(isOperand(s[i])){
                
                 ll value=0;
                
                while(i<n && isOperand(s[i])==true){
                    
                    value=(value*10)+s[i]-'0';
                    i++;
                    
                }
                
                i--;
                
                values.push(value);
                
            }
            
            else if(isOperator(s[i])){
                
                while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){
                    
                    ll val1=values.top();
                    values.pop();
                    
                    ll val2=0;
                    
                    if(!values.empty()){
                        val2=values.top();
                        values.pop();
                    }
                    
                    char ch=ops.top();
                    ops.pop();
                    
                    values.push(applyop(val2,val1,ch));
                    
                }
                
                ops.push(s[i]);
                
            }
            
            else if(s[i]==')'){
                
                while(!ops.empty() && ops.top()!='('){
                    
                    ll val1=values.top();
                    values.pop();
                    
                    ll val2=0;
                    
                    if(!values.empty()){
                        val2=values.top();
                        values.pop();
                    }
                    
                    char ch=ops.top();
                    ops.pop();
                    
                    values.push(applyop(val2,val1,ch));
                    
                }
                
                ops.pop();
                
            }
            
        }
        
        
        while(!ops.empty()){
            
                    ll val1=values.top();
                    values.pop();
                    
                    ll val2=0;
                    
                    if(!values.empty()){
                        val2=values.top();
                        values.pop();
                    }
                    
                    char ch=ops.top();
                    ops.pop();
                    
                    values.push(applyop(val2,val1,ch));
            
        }
        
        return values.top();
        
    }
};