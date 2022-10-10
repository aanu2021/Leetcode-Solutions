class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        if(x[0]==y[0]){
            
            return x[1] < y[1];
            
        }
        
        return x[0] < y[0];
        
    }
    
    int maxEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end());
        
        int n = events.size();
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int i = 0;
        
        int ans = 0;
        
        for(int d=1;d<=100002;d++){
            
            while(!pq.empty() && pq.top()<d){
                
                pq.pop();
                
            }
            
            while(i<n && events[i][0]==d){
                
                pq.push(events[i++][1]);
                
            }
            
            if(!pq.empty()){
                
                ans++;
                pq.pop();
                
            }
            
        }
        
        return ans;
        
    }
};