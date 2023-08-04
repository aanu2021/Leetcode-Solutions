class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string temp = a;
        int moves = 1;
        while(a.length() < b.length()){
            a += temp;
            moves++;
        }
        
        if(a.find(b) != -1){
            return moves;
        }
        
        a += temp;
        moves++;
        
        if(a.find(b) != -1){
            return moves;
        }
        
        return -1;
        
    }
};

/*

a b c d a b c d a b c d

*/

