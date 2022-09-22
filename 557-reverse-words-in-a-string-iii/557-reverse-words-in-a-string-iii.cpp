class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        stack<string>S;
        
        for(int i=n-1;i>=0;i--){
        
            if(s[i]==' '){
                continue;
            }
            
            int j=i;
            
            string str="";
            
            while(j>=0 && s[j]!=' '){
                str+=s[j];
                j--;
            }
            
            S.push(str);
            
            i=j;
            i++;
            
        }
        
        string res="";
        
        while(!S.empty()){
            
            res+=S.top();
            S.pop();
            
            if(!S.empty()){
                res+=" ";
            }
            
        }
        
        return res;
        
    }
};