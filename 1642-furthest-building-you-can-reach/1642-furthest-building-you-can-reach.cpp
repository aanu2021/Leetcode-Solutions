class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i = 0;
        priority_queue<int>pq;
        for(i=0;i<n-1;){
            int diff = heights[i+1] - heights[i];
            if(diff < 0){
                i++; continue;
            }
            if(bricks >= diff){
                bricks -= diff;
                pq.push(diff);
                i++; continue;
            }
            else{
                if(ladders > 0){
                    if(!pq.empty() && pq.top() > diff){
                        bricks += pq.top();
                        pq.pop();
                        bricks -= diff;
                        pq.push(diff);
                    }
                    ladders--;
                    i++; continue;
                }
                else{
                    break;
                }
            }
        }
        return i;
    }
};



    
    