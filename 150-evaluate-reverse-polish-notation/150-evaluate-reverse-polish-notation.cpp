class Solution {
public:
    int evalRPN(vector<string>&vec) {
        
        stack<int>values;
        
        
        for(int i=0;i<vec.size();++i){
            
            if(vec[i]=="+" || vec[i]=="-" || vec[i]=="*" || vec[i]=="/"){
                
                int op2=values.top();
                values.pop();
                
                int op1=values.top();
                values.pop();
                
                if(vec[i]=="+"){
                    values.push(op1+op2);
                }else if(vec[i]=="-"){
                    values.push(op1-op2);
                }else if(vec[i]=="*"){
                    values.push(op1*op2);
                }else{
                    values.push(op1/op2);
                }
                
            }
            
            else{
                
                values.push(stoi(vec[i]));
                
            }
            
        }
        
        
        return values.top();
        
    }
};