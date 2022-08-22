class Solution {
public:
    
    int racecar(int target) {
       
        if(target==0){
            return 0;
        }
        
        queue<pair<int,int>>q;
        
        q.push({0,1});
        
        int lvl=0;
        
        
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
                auto curr=q.front();
                q.pop();
                
                int pos=curr.first;
                int vel=curr.second;
                
                
                if(abs(pos)>2*target){
                    continue;
                }
                
                if(pos==target){
                    return lvl;
                }
                
                
                // A
                
                 q.push({pos+vel,2*vel});
                
                
                // R
                
                 if((pos+vel>target && vel>0) || (pos+vel<target && vel<0)){
                     
                     q.push({pos,(vel>0 ? -1 : 1)});
                     
                 }
                
            }
            
            lvl++;
            
        }
        
        return -1;
        
    }
};