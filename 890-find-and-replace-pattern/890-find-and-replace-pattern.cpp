class Solution {
public:
    
    bool isIsoMorphic(string s,string p){
        
        map<char,char>mapp;
        set<char>S;
        
        for(int i=0;i<s.length();++i){
            
            if(mapp.find(s[i])!=mapp.end()){
                
                if(mapp[s[i]]!=p[i]){
                    return false;
                }
                
            }
            
            else{
                
               if(S.find(p[i])!=S.end()){
                   return false;
               }
                
               mapp[s[i]]=p[i];
               S.insert(p[i]);
                
            }
            
        }
        
        return true;
        
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        
        for(int i=0;i<words.size();++i){
            
            if(isIsoMorphic(words[i],pattern)==true){
                
                ans.push_back(words[i]);
                
            }
            
        }
        
        return ans;
        
    }
};