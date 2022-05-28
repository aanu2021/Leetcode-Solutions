class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int maxval=days.back();
        
        vector<int>dp(maxval+1,0);
        
        set<int>st;
        
        for(int i:days){
            st.insert(i);
        }
        
        for(int i=1;i<=maxval;i++){
            
            if(st.find(i)!=st.end()){
                
                int c1=dp[i-1];
                int c7=(i-7>=0 ? dp[i-7] : 0);
                int c30=(i-30>=0 ? dp[i-30] : 0);
                
                dp[i]=min(c1+costs[0],min(c7+costs[1],c30+costs[2]));
                
            }
            
            else{
                
                dp[i]=dp[i-1];
                
            }
            
        }
        
        return dp[maxval];
        
    }
};