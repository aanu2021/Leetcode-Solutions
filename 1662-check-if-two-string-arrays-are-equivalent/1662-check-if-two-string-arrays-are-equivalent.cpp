class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        int w1 = 0,w2 = 0;
        int p1 = 0,p2 = 0;
        
        while(w1 < m && w2 < n){
            
            if(word1[w1][p1]!=word2[w2][p2]) return false;
            
            if(p1 < word1[w1].length()-1){
                p1++;
            }else{
                p1=0; w1++;
            }
            
            if(p2<word2[w2].length()-1){
                p2++;
            }else{
                p2=0; w2++;
            }
            
        }
        
        return w1==m && w2==n;
        
    }
};


