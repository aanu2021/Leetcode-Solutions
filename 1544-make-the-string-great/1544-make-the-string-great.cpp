class Solution {
public:
    
    string makeGood(string s) {
       
        int end = 0;
        
        for(int cur=0;cur<s.length();cur++){
            
            if(end>0 && abs(s[cur]-s[end-1])==32){
                end--;
            }
            
            else{
                s[end] = s[cur];
                end++;
            }
            
        }
        
        return s.substr(0,end);
        
    }
};


  