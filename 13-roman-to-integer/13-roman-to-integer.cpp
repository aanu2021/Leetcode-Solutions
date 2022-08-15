class Solution {
public:
    
    int value(char ch){
        
        switch(ch){
                
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;    
                
        }
        
        return 0;
        
    }
    
    int romanToInt(string s) {
        
        int curr_value=0;
        int prev_value=0;
        
        int n=s.length();
        
        for(int i=n-1;i>=0;i--){
            
            if(value(s[i])>=prev_value){
                curr_value+=value(s[i]);
            }
            else{
                curr_value-=value(s[i]);
            }
            
            prev_value=value(s[i]);
            
        }
        
        return curr_value;
        
    }
};