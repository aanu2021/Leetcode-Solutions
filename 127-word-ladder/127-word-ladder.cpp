class Solution {
public:
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        
        unordered_set<string>S;
        
        for(string str:wordList){
            
            S.insert(str);
            
        }
        
        
        queue<string>q;
        q.push(bW);
        
        S.erase(bW);
        
        if(S.find(eW)==S.end()){
            return 0;
        }
        
        
        int level=0;
        
        string curr="";
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                curr=q.front();
                q.pop();
                
                if(curr==eW){
                    return 1+level;
                }
                
                for(int i=0;i<curr.length();++i){
                    
                    char ch=curr[i];
                    
                    for(char c='a';c<='z';c++){
                        
                        curr[i]=c;
                        
                        if(S.find(curr)!=S.end()){
                            
                            S.erase(curr);
                            
                            q.push(curr);
                            
                        }
                        
                        
                    }
                    
                    curr[i]=ch;
                    
                }
                
            }
            
            level++;
            
        }
        
        return 0;
        
    }
};