class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        
        int sum=0;
        
        priority_queue<int>pq;
        
        int i=0;
        
        for(i=0;i<n-1;){
            
            if(heights[i]>=heights[i+1]){
                ++i;
                continue;
            }
            
            int curr=heights[i+1]-heights[i];
            
            if(sum+curr<=bricks){
                
                sum+=curr;
                pq.push(curr);
                i++;
                continue;
                
            }
            
            else if(ladders>0){
                
                sum+=curr;
                
                pq.push(curr);
                
                sum-=pq.top();
                
                pq.pop();
                
                ladders--;
                
                i++;
                
                continue;
                
            }
            
            else{
                
                break;
                
            }
            
        }
        
        return i;
        
    }
};