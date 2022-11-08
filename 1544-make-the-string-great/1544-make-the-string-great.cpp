class Solution {
public:
    string makeGood(string s) {
       
        int n = s.length();
        
        int left = 0, right = 0;
        
        for(right=0;right<n;right++){
            
            if(left>0 && abs(s[left-1]-s[right])==32){
                left--;
            }else{
                s[left] = s[right];
                left++;
            }
            
        }
        
        return s.substr(0,left);
        
    }
};


  