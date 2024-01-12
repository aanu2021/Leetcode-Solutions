class Solution {
public:
    
    int calc(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
        else return 0;
    }
    
    bool halvesAreAlike(string s) {
        int n = s.length();
        int totEven = 0, currEven = 0;
        for(int i=0;i<n;i++){
            totEven += calc(s[i]);
            if(i < (n/2)){
                currEven += calc(s[i]);
            }
        }
        if(totEven%2) return false;
        if(currEven == (totEven/2)) return true;
        else return false;
    }
};