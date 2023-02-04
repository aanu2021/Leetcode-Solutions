class Solution {
public:
    
    /*
    
    For those who are having issues with TLE , here comes the optimized version , that will definitely pass any 
    kind of tight constraints.
    
    Approach : Precomputation with prefix array + Dynamic Programming
    
    Crux of the problem : To figure out total number of integers present in a subarray [a(l) ... a(r)] , which 
    occurs greater than one.
    
    So first somehow we need to calculate that one , now one can easily use a map along with recursion + 
    memoization to accomplish that , but due to LC's tight time constraint there might be a possibility that they 
    end up with a TLE :(
    
    To get rid of this situation , we need to precompute that "number of integers present in a subarray a[l...r] , 
    which occurs more than once".
    
    Let's try to make an observation with an example subarray.
    
    1 , 2 , 0 , 2 , 1 , 3 , 2
    
    score = 0
    occ -> denotes the occurence of current integer nums[j] , in the subarray [0....j].
    
    More formally , 
    
    occ[val][endIndex] --> total occurence of val , in the subarray starting at index 0 , and ending at index 
    endIndex.
    
    Now , 
    
    Iteration 1 :
    
    occ[1][0] --> 1 (doesn't occur more than once)
    
    score = 0
    
    
    Iteration 2 :
    
    occ[2][1] --> 1 (doesn't occur more than once)
    
    score = 0
    
    
    Iteration 3 :
    
    occ[0][2] --> 1 (doesn't occur more than once)
    
    score = 0
    
    
    Iteration 4 :
    
    occ[2][3] --> 2 (here comes the twist , occurence of 2 reaches more than once , so our score will be 
    incremented by 2 , because we need to pick up all the integers which occurs more than once {> 1} )
    
    score += 2
    score = 2
    
    
    Iteration 5 :
    
    occ[1][4] --> 2 (same logic)
    
    score += 2   
    score = 4
    
    
    Iteration 6 : 
    
    occ[3][5] --> 1 (no extra score will be added , as it occurs only once , so it gets trimmed afterwards anyway)
    
    score += 0
    score = 4
    
    
    Iteration 7 :
    
    occ[2][6] --> 3 (Here comes the last and final twist when occurence of an integer exceeds 2 , i.e { >= 3} )
    
    score += 3
    score = 7
    
    but is it correct ???
    
    number of integers which occur more than once {2,2,2,1,1}  ->  in total it should be equal to 5 but why the 
    extra +2 in cour final score .
    
    Remember we already add the contribution of integer "val" beforehand , where we already added score += prevocc
    
    and prevocc == currentocc - 1
    
    then we have to first decrease our total score by prevocc and then add the currentOcc to nullify the extra 
    score's effect.
    
    Final score = score - prevOcc = 7 - 2 = 5.
    
    
    
    Now the only headache is how to efficiently determine the occurence of an integer in a subarray , for that just
    maintain a prefix array which will store the occurence of number "val" , till index "endingIndex".
    
    For a fixed startingIndex, we can calculate the occurence of "val" , in any of the subarray ending at 
    endingIndex. sounds confusing , just have a look at my solution code , and hopefully , it will be crystal 
    clear.
    
    Time Complexity : O(N*N)
    Space Complexity : O(N*N)
    
    Please upvote for better reach.
    
    */
    
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>prefix(n+5,vector<int>(n+5,0));
        for(int i=0;i<n;i++){
            prefix[i][nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        vector<int>dp(n+5,1e9 + 1e5);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--){
            int val = 0;
            for(int j=i;j<n;j++){
                int occ = prefix[j][nums[j]] - (i-1>=0 ? prefix[i-1][nums[j]] : 0);
                    if(occ == 2){
                        val+=2;
                    }
                    else if(occ > 2){
                        val -= (occ-1);
                        val += occ;
                    }
                dp[i] = min(dp[i],val + k + dp[j+1]);
            }
        }
        return dp[0];
    }
};