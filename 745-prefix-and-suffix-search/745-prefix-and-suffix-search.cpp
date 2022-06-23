class WordFilter {
public:
    
    unordered_map<string,int>Map;
    
    WordFilter(vector<string>& words) {
        
        string str="";
        
        string prefix="";
        
        string suffix="";
        
        
        for(int i=0;i<words.size();++i){
            
            str=words[i];
            
            for(int j=0;j<str.length();++j){
                
                for(int k=0;k<str.length();++k){
                    
                    prefix=str.substr(0,j+1);
                    suffix=str.substr(k);
                    
                    Map[prefix+"|"+suffix]=i+1;
                    
                }
                
            }
            
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        string ans=prefix+"|"+suffix;
        
        return Map[ans]-1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */