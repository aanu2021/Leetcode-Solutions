class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    }
    
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n=courses.size();
        
        sort(courses.begin(),courses.end(),comp);
        
        int count=0;
        
        int timer=0;
        
        priority_queue<int>pq;
        
        
        for(int i=0;i<n;++i){
            
            if(timer+courses[i][0]<=courses[i][1]){
                
                timer+=courses[i][0];
                
                pq.push(courses[i][0]);
                
                count++;
                
            }
            
            else{
                
               if(!pq.empty() && pq.top()>courses[i][0]){
                   
                   timer-=pq.top();
                   pq.pop();
                   
                   timer+=courses[i][0];
                   pq.push(courses[i][0]);
                   
               }
                
            }
            
        }
        
        return count;
        
    }
};