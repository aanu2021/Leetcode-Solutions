    
/*


 Well , the initial approach that hits our brain , is to use the 
 bricks first to jump from i-th building to (i+1)-th building , 
 and when we have no such sufficient brocks to make the current 
 jump to the next building , then use the ladder for make these 
 possible.
 
 Wait wait wait , don't start to code , first think deeply is the
 above mentioned algo full proof for all the cases or not .
 
 Brain-Storming Example : [1,5,4,6,8]
 
                          bricks = 4   ladder = 1
                          
 Try to do a dry run on these example with the discussed algo ,
 what we will figure out that it is not optimal forever , it might 
 happen then if we use the ladders first , then we are left with 
 sufficient amount of bricks , which will help to make maximum 
 number of jumps in future.
 
 Hmmmmmm , quite tricky na
 
 Let's try to make some observations , 
 
 Obs 1. Ladder is independent of height difference b/w two 
 consecutive buildings , i.e if we have atleast one ladder as of 
 now , we can jump a height of 1 unit , 10 unit , 15 unit , 
 ......., 1000 unit and so on.
 
 Obs 2. But bricks count is bounded and we need to spend them 
 greedily. 
 
 Obs 3. What if we use our ladder(is we have currently) for those 
 consecutive height differences , which are larger ones 
 comparatably than the others.
 
 Like , Height Differences are given 4,6,3,7,9  and we have ladder
 count 2 initially , then it is more optimal to use that for first 
 two maximum differences , like for prefix [4,6,3] maximum ones 
 are [6 and 9] , in the same manner for the prefix [4,6,3,7] 2 
 (ladder_cnt) Maximum ones are [6 and 7].
 
 
 
 Algorithm :
 
 We will initially use those ladders as long as possible , then 
 the time will appear , when we have zero numbers of ladders , we 
 have only option left , i.e to use the bricks but before doing so
 , we will check whether the current height difference is the not
 among the ladder_cnt Maximum differences till the current prefix 
 or not.
 
 For maintaing the previous differences from minimum to 
 maximum(sorted order), the DS that we will use is Minheap / 
 Priority Queue.
 

Approach : Greedy
 
T.C : O(N*logN)
S.C : O(N)


*/
    

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
       int n = heights.size();
        
        int i = 0;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(i=0;i<n-1;i++){
            
            int curr_diff = heights[i+1] - heights[i];
            
            if(curr_diff <= 0) continue;
            
            pq.push(curr_diff);
            
            if(pq.size() > ladders){
                
                bricks -= pq.top();
                pq.pop();
                
            }
            
            if(bricks < 0) return i;
            
        }
        
        return n-1;
        
    }
};