class Solution {
public:
    string pushDominoes(string s) {
     
        int n=s.length();
        
        s="L"+s+"R";
        
        string res="";
        
        for(int i=0,j=1;j<s.length();j++){
            
            if(s[j]=='.') continue;
            
            if(i>0) res+=s[i];
            
            int middle=(j-i-1);
            
            if(s[i]==s[j]){
                
                for(int k=0;k<middle;k++){
                    res+=s[i];
                }
                
            }
            
            else if(s[i]=='L' && s[j]=='R'){
                
                for(int k=0;k<middle;k++){
                    res+='.';
                }
                
            }
            
            else{
                
                if(middle&1){
                    
                    for(int k=0;k<middle/2;k++){
                        res+="R";
                    }
                    
                    res+=".";
                    
                    for(int k=0;k<middle/2;k++){
                        res+="L";
                    }
                    
                }
                
                else{
                    
                    for(int k=0;k<middle/2;k++){
                        res+="R";
                    }

                    for(int k=0;k<middle/2;k++){
                        res+="L";
                    }
                    
                }
                
            }
            
            i=j;
            
        }
        
        return res;
        
    }
};