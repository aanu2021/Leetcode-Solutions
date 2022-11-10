class Solution {
public:
    int findLongestChain2(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
    int findLongestChain3(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector<int>dp(n,1);
        
        for(int i=n-2;i>=0;i--){
            
            int inc = -1;
            int low = i+1,high = n-1;
            
            while(low<=high){
                int mid = (low + high)/2;
                if(pairs[mid][0] > pairs[i][1]){
                    inc = mid;
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            
            int curr_chain = 1;
                
            if(inc!=-1){
                curr_chain += dp[inc];
            }
            dp[i] = max(dp[i+1],curr_chain);
        }
        
        return dp[0];
    }
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[1] < y[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int ans = 0 , curr = INT_MIN;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0] > curr){
                curr = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
    
};


/* 

a,b
c,d

c>b
c>a

sort on the basis of starting time.
    
    a,b  c,d  e,f  g,h  i,j
    
    Where , a <= c <= e <= g <= i
    
    Check for the current interval , for all the intervals appeared before these having ending[j] < starting[i] (j < i)
        
*/

/*

Greedy Approach : Let's say we have a set of intervals already added to our pouch , now to increase the chain length we wanna add a new interval , satisfying the given conditions.

i.e interval[j][0] > interval[i][1]

    We gonna add that interval , which has the smallest possible interval[j][1] .
    
    a,b  c,d
    
    b < d
    
    if(b < c)  then add [a,b] first 
    
    if(b>=c)  then what should be the optimal way.
    
    d>b && b>a --> d>a
    
    That means we can take atmost one pair in our chain , but which one ???
    
    [a,b] by taking these it will enable us to add more pairs with start > b.

*/
        