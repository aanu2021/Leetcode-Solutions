class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    } 
    
    int scheduleCourse(vector<vector<int>>& c) {
        
        sort(c.begin(),c.end(),comp);
        
        int sum=0;
        
        priority_queue<int>pq;
        
        int ans=0;
        
        for(int i=0;i<c.size();i++){
            
            if(sum+c[i][0]<=c[i][1]){
                
                sum+=c[i][0];
                pq.push(c[i][0]);
                ans++;
                
            }
            
            else if(!pq.empty() && pq.top()>c[i][0]){
                
                sum-=pq.top();
                pq.pop();
                
                sum+=c[i][0];
                
                pq.push(c[i][0]);
                
                
            }
            
        }
        
        return ans;
        
    }
};