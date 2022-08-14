class Solution {
public:
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        
        unordered_set<string>S;
        
        for(string str:wordList){
            S.insert(str);
        }
        
        int level=0;
        
        queue<string>q;
        
        q.push(bW);
        
        string curr="";
        
        S.erase(bW);
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                curr=q.front();
                q.pop();
                
                if(curr==eW){
                    return (1 + level);
                }
                
                
                for(int i=0;i<curr.length();++i){
                    
                    char ch=curr[i];
                    
                    for(char c='a';c<='z';c++){
                        
                        curr[i]=c;
                        
                        if(S.find(curr)!=S.end()){
                            
                            q.push(curr);
                            S.erase(curr);
                            
                        }
                        
                        curr[i]=ch;
                        
                    }
                    
                }
                
            }
            
            level++;
            
        }
        
        return 0;
        
    }
};