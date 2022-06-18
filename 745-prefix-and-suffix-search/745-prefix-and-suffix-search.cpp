class WordFilter {
public:
    
    unordered_map<string,int>hashmap;
    
    WordFilter(vector<string>& words) {
        
        int n=words.size();
        
        string str="";
        
        string p="",s="";
        
        for(int i=0;i<n;i++){
            
            str=words[i];
            
            int len=str.length();
            
            for(int j=0;j<len;j++){
                
                for(int k=0;k<len;k++){
                    
                    p=str.substr(0,j+1);
                    s=str.substr(k);
                    
                    hashmap[p+"|"+s]=i+1;
                    
                }
                
            }
            
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        return hashmap[prefix+"|"+suffix]-1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */