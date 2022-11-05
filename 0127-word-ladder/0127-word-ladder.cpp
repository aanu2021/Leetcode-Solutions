class Solution {
public:
    
    int ladderLength(string bW, string eW, vector<string>& wordList) {
        
        queue<string>q;
        
        unordered_set<string>dict;
        unordered_set<string>vis;
        
        q.push(bW);
        vis.insert(bW);
        
        for(string&str:wordList){
            dict.insert(str);
        }
        
        int lvl = 1;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto str = q.front();
                q.pop();
                
                if(str==eW){
                    return lvl;
                }
                
                for(int i=0;i<str.length();i++){
                    
                    char temp = str[i];
                    
                    for(char ch='a';ch<='z';ch++){
                        
                        str[i] = ch;
                        
                        if(dict.find(str)!=dict.end() && vis.find(str)==vis.end()){
                            
                            q.push(str);
                            vis.insert(str);
                            
                        }
                        
                    }
                    
                    str[i] = temp;
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return 0;
        
    }
};