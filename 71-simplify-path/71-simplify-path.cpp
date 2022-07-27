class Solution {
public:
    string simplifyPath(string s) {
        
        int n=s.length();
        
        stack<string>S;
        
        for(int i=0;i<n;++i){
            
            if(s[i]=='/'){
                continue;
            }
            
            string temp="";
            
            while(i<n && s[i]!='/'){
                temp+=s[i];
                i++;
            }
            
            if(temp=="."){
                continue;
            }
            
            else if(temp==".."){
                if(S.empty()){
                    continue;
                }else{
                    S.pop();
                }
            }
            
            else{
                S.push(temp);
            }
            
        }
        
        string res="";
        
        while(!S.empty()){
            res="/"+S.top()+res;
            S.pop();
        }
        
        if(res.length()==0){
            return "/";
        }else{
            return res;
        }
        
    }
};