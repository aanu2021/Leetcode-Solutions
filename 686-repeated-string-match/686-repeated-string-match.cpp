class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int moves=1;
        
        string temp=a;
        
        while(a.length()<b.length()){
            
            a+=temp;
            moves++;
            
        }
        
        if(a.find(b)!=-1){
            return moves;
        }
        
        a+=temp;
        moves++;
        
        if(a.find(b)!=-1){
            return moves;
        }
        
        return -1;
        
    }
};


