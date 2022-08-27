class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string str="";
        
        for(int i=0;i<n;++i){
            str+="a";
        }
        
        k-=n;
        
        for(int i=n-1;i>=0;i--){
            
            if(k>=25){
                str[i]='z';
                k-=25;
            }
            
            else{
                str[i]=(char)('a'+k);
                break;
            }
            
        }
        
        return str;
        
    }
};