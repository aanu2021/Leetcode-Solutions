class Solution {
public:
    
    int n,k,wordLen,substringSize;
    
    unordered_map<string,int>wordCount;
    
    vector<int>ans;
    
    void func(string &s,int left){
        
        unordered_map<string,int>wordFound;
        
        int total=0;
        
        bool excess=false;
        
        for(int right=left;right<=n-wordLen;right+=wordLen){
            
            string sub=s.substr(right,wordLen);
            
            if(wordCount.find(sub)==wordCount.end()){
                
                total=0;
                excess=false;
                wordFound.clear();
                left=right+wordLen;
                
            }
            
            else{
                
                while((right-left==substringSize) || excess){
                    
                    string left_word=s.substr(left,wordLen);
                    
                    left+=wordLen;
                    
                    wordFound[left_word]--;
                    
                    if(wordFound[left_word]==wordCount[left_word]){
                        
                        excess=false;
                        
                    }
                    
                    else{
                        
                        total--;
                        
                    }
                    
                }
                
                wordFound[sub]++;
                
                if(wordFound[sub]<=wordCount[sub]){
                    total++;
                }
                else{
                    excess=true;
                }
                
                if(total==k && !excess){
                    ans.push_back(left);
                }
                
            }
            
        }
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        n=s.length();
        k=words.size();
        wordLen=words[0].length();
        substringSize=(k*wordLen);
        
        
        for(string str:words){
            wordCount[str]++;
        }
        
        
        for(int i=0;i<wordLen;++i){
            
            func(s,i);
            
        }
        
        
        return ans;
        
    }
};