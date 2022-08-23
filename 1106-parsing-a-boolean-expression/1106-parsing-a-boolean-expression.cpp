class Solution {
public:
    bool parseBoolExpr(string s) {
        
        int n=s.length();
        
        stack<char>s1,s2;
        
        // s1 --> operator
        // s2 --> operator , operands
        
        
        for(int i=0;i<n;++i){
            
            if(s[i]==')'){
                
                char ops=s1.top();
                s1.pop();
                
                if(ops=='&'){
                    
                    char val=s2.top();
                    s2.pop();
                    
                    while(!s2.empty() && s2.top()!=ops){
                        
                        char val1=s2.top();
                        s2.pop();
                        
                        if(val=='t' && val1=='t'){
                            val='t';
                        }else{
                            val='f';
                        }
                        
                    }
                    
                    s2.pop();
                    s2.push(val);
                    
                }
                
                else if(ops=='|'){
                    
                    char val=s2.top();
                    s2.pop();
                    
                    while(!s2.empty() && s2.top()!=ops){
                        
                        char val1=s2.top();
                        s2.pop();
                        
                        if(val=='f' && val1=='f'){
                            val='f';
                        }else{
                            val='t';
                        }
                        
                    }
                    
                    s2.pop();
                    s2.push(val);
                    
                }
                
                else{
                    
                    char val=s2.top();
                    s2.pop();
                    
                    if(val=='t'){
                        val='f';
                    }else{
                        val='t';
                    }
                    
                    s2.pop();
                    s2.push(val);
                    
                }
                
            }
            
            else{
                
                if(s[i]=='|' || s[i]=='&' || s[i]=='!'){
                    s1.push(s[i]);
                }
                
                if(s[i]!=',' && s[i]!='('){
                    s2.push(s[i]);
                }
                
            }
            
        }
        
        if(s2.top()=='t'){
            return true;
        }else{
            return false;
        }
        
    }
};