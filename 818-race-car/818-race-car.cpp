class Solution {
public:
    
    int racecar(int target) {
       
        if(target==0){
            return 0;
        }
        
        int dist[100005];
        
        memset(dist,1e9,sizeof(dist));
        
        dist[0]=0;
        
        queue<pair<int,int>>q;
        
        q.push({0,1});
        
        set<pair<int,int>>S;
        
        int lvl=0;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int pos=curr.first;
                int vel=curr.second;
                
                
                if(S.find({pos,vel})!=S.end()){
                    continue;
                }
                
                S.insert({pos,vel});
                
                if(abs(pos)>2*target){
                    continue;
                }
                
                if(pos==target){
                    return lvl;
                }
                
                
                // A
                
                 q.push({pos+vel,2*vel});
                
                
                // R
                
                 q.push({pos,(vel>0 ? -1 : 1)});
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
};