class Solution {
public:
    int minMutation(string start, string end, vector<string>& b) {
        
        unordered_set<string>bank;
        
        for(string str:b){
            bank.insert(str);
        }
        
        unordered_set<string>visited;
        
        queue<string>q;
        
        vector<char>genes = {'A','T','C','G'};
        
        q.push(start);
        
        int lvl = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                auto curr = q.front();
                q.pop();
                
                if(curr==end) return lvl;
                
                if(visited.find(curr)!=visited.end()){
                    continue;
                }
                
                visited.insert(curr);
                
                for(int i=0;i<curr.length();++i){
                    
                    char temp = curr[i];
                    
                    for(char ch:genes){
                        
                        curr[i] = ch;
                        
                        if(visited.find(curr)==visited.end() && bank.find(curr)!=bank.end()){
                            
                            q.push(curr);
                            
                        }
                        
                    }
                    
                    curr[i] = temp;
                    
                }
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
};