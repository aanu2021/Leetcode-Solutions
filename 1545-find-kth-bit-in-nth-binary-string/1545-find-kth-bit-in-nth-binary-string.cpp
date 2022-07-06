class Solution {
public:
    
    string revert(string &s){
        
        string res="";
        
        for(int i=0;i<s.length();++i){
            if(s[i]=='0'){
                res+="1";
            }else{
                res+="0";
            }
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
    
    char findKthBit(int n, int k) {
        
        string s="0";
        
        int m=n;
        
        n--;
        
        string res="";
        
        while(n>0){
            
            res+=s;
            res+="1";
            res+=revert(s);
            
            s=res;
            res="";
            
            n--;
            
        }
        
        return s[k-1];
        
    }
};