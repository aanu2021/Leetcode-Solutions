class Solution {
public:
    
    bool static comp(vector<int>&x,vector<int>&y){
        return x[1] < y[1];
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        
        sort(c.begin(),c.end(),comp);
        
        priority_queue<int>pq;
        
        int total=0;
        
        int ans=0;
        
        for(int i=0;i<c.size();i++){
            
            if(total+c[i][0]<=c[i][1]){
                
                total+=c[i][0];
                
                pq.push(c[i][0]);
                
                ans++;
                
            }
            
            else{
                
                if(!pq.empty() && pq.top()>c[i][0]){
                    
                    total-=pq.top();
                    pq.pop();
                    
                    total+=c[i][0];
                    pq.push(c[i][0]);
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};