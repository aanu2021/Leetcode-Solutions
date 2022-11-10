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
    
    int findLongestChain(vector<vector<int>>& pairs) {
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
        