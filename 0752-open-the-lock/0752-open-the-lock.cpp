class Solution {
public:
    
    char increment(char ch){
        int val = (int)(ch-'0');
        val++;
        val %= 10;
        return (char)(val + '0');
    }
    
    char decrement(char ch){
        int val = (int)(ch - '0');
        val--;
        val += 10;
        val %= 10;
        return (char)(val + '0');
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>obstacle;
        for(string &str : deadends){
            obstacle.insert(str);
        }
        queue<string>q;
        unordered_set<string>visited;
        visited.insert("0000");
        q.push("0000");
        if(obstacle.find("0000") != obstacle.end()) return -1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                // cout<<node<<" "<<lvl<<"\n";
                if(node == target) return lvl;
                for(int i=0;i<4;i++){
                    char temp = node[i];
                    node[i] = increment(node[i]);
                    if(obstacle.find(node) == obstacle.end()){
                        if(visited.find(node) == visited.end()){
                            visited.insert(node);
                            q.push(node);
                        }
                    }
                    node[i] = temp;
                    node[i] = decrement(node[i]);
                    if(obstacle.find(node) == obstacle.end()){
                        if(visited.find(node) == visited.end()){
                            visited.insert(node);
                            q.push(node);
                        }
                    }
                    node[i] = temp;
                }
            }
            lvl++;
        }
        return -1;
    }
};