class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>S;
        
        for(int i=0;i<words.size();++i){
            
            string str="";
            
            for(int j=0;j<words[i].length();++j){
                
                str+=vec[words[i][j]-'a'];
                
            }
            
            S.insert(str);
            
        }
        
        return S.size();
        
    }
};