class Solution {
public:
    
    /*
    
    Approach : Dynamic Programming
    
    T.C : O(target*log2(target))
    S.C : O(target)
    
    */
    
    /*
    
    dp[i] --> represents minimum number of steps required to
    reach 'i' from the source , with +1 initial speed.
    
    Base Case :
    
    If x == 2^r - 1 , then minimum number of moves requires to 
    reach point i , is r [2^0 + 2^1 + 2^2 + .... + 2^(r-1)] = 
    Total of (r-1+1) = r number of moves
    
    Recurrence Relation and Transitions :
    
    If 2^(r-1) - 1 < x < 2^r - 1 ,
    
    Now here arises two possibilites ...........
    
    Possibility (1) :
    
    First we reach 2^(r-1) - 1 , then reverse our direction 
    (after reversing our initial speed resets to '-1' , -1 means 
    +1 initial speed in the negative direction) .
    
    Then use j moves in the opposite direction , after that we
    finally reach the point [ [2^(r-1) - 1] - [2^j - 1] ]
    = 2^(r-1) - 2^j , now from these point we need to reverse our
    direction again and starts moving in the positive direction 
    to reach the target point 'i'.
    
    Total number of operations needed 
    = (r-1) + 1(rev) + j + 1(rev) + dp[i-(pow(2,r-1)-pow(2,j))]
    =  r + 1 + j + dp[i - pow(2,r-1) + pow(2,j)]
    
    Possibility (2) :
    
    First we have to reach the point 2^r , then from there we 
    will reverse our direction , and cover the remaining distance 
    by using dp[2^r - 1 - i] moves.
    
    Total number of operations needed 
    = r + 1(rev) + dp[pow(2,r) - 1 - i]
    
    */

    
    int racecar(int target) {
        
        vector<int>dp(target+1,1e9);
        
        dp[0] = 0;
        
        int r = 1;
        
        for(int i=1;i<=target;i++){
            
            if(i==pow(2,r)-1){
                
                dp[i] = r;
                
                r++;
                
            }
            
            else{
                
                for(int j=0;j<r-1;j++){
                    
                    dp[i] = min(dp[i],r+1+j+dp[i-pow(2,r-1)+pow(2,j)]);
                    
                }
                
                dp[i] = min(dp[i],r+1+dp[pow(2,r) - 1 - i]);
                
            }
            
        }
        
        return dp[target];
        
    }
};