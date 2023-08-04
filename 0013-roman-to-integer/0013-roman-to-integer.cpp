class Solution {
public:
    
    int getValue(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int n = s.length();
        int currSum = 0;
        int prev_value = 0;
        for(int i=n-1;i>=0;i--){
            if(getValue(s[i]) >= prev_value){
                currSum += getValue(s[i]);
            }
            else{
                currSum -= getValue(s[i]);
            }
            prev_value = getValue(s[i]);
        }
        return currSum;
    }
};