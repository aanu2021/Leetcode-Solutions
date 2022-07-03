class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        
        int maxscore=0;
        
        int currscore=0;
        
        int n=tokens.size();
        
        if(n==0){
            return 0;
        }
        
        if(power<tokens[0]){
            return 0;
        }
        
        int i=0,j=n-1;
        
        while(i<=j){
            
            if(tokens[i]<=power){
                power-=tokens[i];
                i++;
                currscore++;
                maxscore=max(maxscore,currscore);
            }
            
            else if(i<=j && tokens[i]>power && currscore>=1){
                currscore--;
                power+=tokens[j];
                j--;
            }
            
            else{
                
                break;
                
            }
            
        }
        
        return maxscore;
        
    }
};