class Solution {
public:
    int maxLength(vector<string>&vec) {
        
        int n=vec.size();
        
        int maxLen=0;
        
        for(int i=0;i<(1<<n);++i){
            
            string str="";
            
            for(int j=0;j<n;++j){
                
                if((i&(1<<j))){
                    
                    str+=vec[j];   
                    
                }
                
            }
            
            vector<int>freq(26,0);
            
            for(char c:str){
                freq[c-'a']++;
            }
            
            bool flag=true;
            
            for(int j=0;j<26;++j){
                if(freq[j]>1){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                
                maxLen=max(maxLen,(int)str.length());
                
            }
            
        }
        
        return maxLen;
        
    }
};