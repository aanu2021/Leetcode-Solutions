class Solution {
public:
    
    typedef long long ll;
    
    bool isOperator(string &op){
        if(op=="+" || op=="-" || op=="*" || op=="/") return true;
        else return false;
    }
    
    ll apply_operation(ll val1,ll val2,string opr){
        if(opr=="+") return val1+val2;
        if(opr=="-") return val1-val2;
        if(opr=="*") return val1*val2;
        if(opr=="/") return val1/val2;
        return 0LL;
    }
    
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<ll>S;
        for(int i=0;i<n;i++){
            if(isOperator(tokens[i])){
                ll val2 = S.top(); S.pop();
                ll val1 = S.top(); S.pop();
                S.push(apply_operation(val1,val2,tokens[i]));
            }
            else{
                S.push(stoll(tokens[i]));
            }
        }
        return S.top();
    }
};