class WordFilter {
public:
    
    unordered_map<string,int>hashmap;
    
    WordFilter(vector<string>& words) {
        
        int n=words.size();
        
        for(int i=0;i<n;i++){
            
            string str=words[i];
            
            int len=str.length();
            
            for(int j=0;j<len;j++){
                
                for(int k=0;k<len;k++){
                    
                    int len1=j+1;
                    int len2=(len-k);
                    
                    // if(len1+len2>len){
                    //     continue;
                    // }
                    
                    string prefix=str.substr(0,len1);
                    string suffix=str.substr(k);
                    
                    hashmap[prefix+"|"+suffix]=i+1;
                    
                }
                
            }
            
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        string str=prefix+"|"+suffix;
        
        return hashmap[str]-1;
        
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */