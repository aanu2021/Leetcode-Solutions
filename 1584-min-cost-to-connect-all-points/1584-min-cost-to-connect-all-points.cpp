class Solution {
public:
    
    typedef long long ll;
    
    struct comp{
      
        bool operator()(const pair<int,int>&x,const pair<int,int>&y){
            return x.second > y.second;
        }
        
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        vector<bool>visited(n,false);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        pq.push({0,0});
        
        ll ans=0LL;
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int i=curr.first;
            int wt=curr.second;
            
            if(visited[i]==true){
                continue;
            }
            
            visited[i]=true;
            
            ans+=wt;
            
            int x=points[i][0];
            int y=points[i][1];
            
            for(int j=0;j<n;j++){
                
                if(j==i || visited[j]==true){
                    continue;
                }
                
                int dist=abs(points[j][0]-x)+abs(points[j][1]-y);
                
                pq.push({j,dist});
                
            }
            
        }
        
        return ans;
        
    }
};