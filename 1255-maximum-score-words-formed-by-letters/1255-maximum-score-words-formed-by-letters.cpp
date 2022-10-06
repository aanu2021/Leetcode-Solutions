class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int>freq1(26,0);
        
        for(char ch:letters){
            freq1[ch-'a']++;
        }
        
        int maxscore = 0;
        
        int n = words.size();
        
        for(int i=0;i<(1<<n);i++){
            
            vector<int>freq2(26,0);
            
            for(int j=0;j<n;j++){
                
                if((i&(1<<j))){
                    
                    for(char ch:words[j]){
                        
                        freq2[ch-'a']++;
                        
                    }
                    
                }
                
            }
            
            bool flag = true;
            
            for(int j=0;j<26;j++){
                
                if(freq1[j] < freq2[j]){
                    
                    flag = false;
                    break;
                    
                }
                
            }
            
            if(flag){
                
                int currscore = 0;
                
                for(int j=0;j<26;j++){
                    
                    currscore += (freq2[j]*score[j]);
                    
                }
                
                maxscore = max(maxscore,currscore);
                
            }
            
        }
        
        return maxscore;
        
    }
};