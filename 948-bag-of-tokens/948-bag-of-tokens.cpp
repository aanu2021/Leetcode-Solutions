class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       
        int n=tokens.size();
        
        sort(tokens.begin(),tokens.end());
        
        int max_score=0;
        
        int curr_score=0;
        
        int i=0,j=n-1;
        
        while(i<=j){
            
            if(power>=tokens[i]){
                
                curr_score++;
                
                power-=tokens[i];
                
                i++;
                
            }
            
            else{
                
                if(curr_score>0){
                    
                    curr_score--;
                 
                    power+=tokens[j];

                    j--;   
                    
                }
                
                else{
                    
                    break;
                    
                }
                
            }
            
            max_score=max(max_score,curr_score);
            
        }
        
        return max_score;
        
    }
};