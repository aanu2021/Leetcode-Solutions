class Solution {
public:
    
    char flip(char c){
        if(c == '0') return '1';
        else return '0';
    }
    
    int minOperations(string s) {
        int n = s.length();
        int minOps = 0;
        char c = '0';
        int currOps = 0;
        for(int i=0;i<n;i++){
            if(s[i] != c) currOps++;
            c = flip(c);
        }
        minOps = currOps;
        currOps = 0;
        c = '1';
        for(int i=0;i<n;i++){
            if(s[i] != c) currOps++;
            c = flip(c);
        }
        minOps = min(minOps, currOps);
        return minOps;
    }
};