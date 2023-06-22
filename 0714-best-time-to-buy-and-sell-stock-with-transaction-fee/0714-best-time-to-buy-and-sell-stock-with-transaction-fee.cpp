class Solution {
public:
    
    int dp[50005][2];
    
    int func(vector<int>&prices,int i,bool bought,int n,int fee)
    {
        if(i == n) return 0;
        if(dp[i][bought] != -1) return dp[i][bought];
        
        // skip
        
        int answer = func(prices,i+1,bought,n,fee);
        
        // pick 
        
        if(bought){
            answer = max(answer,-prices[i] + func(prices,i+1,false,n,fee));
        }
        else{
            answer = max(answer,prices[i] - fee + func(prices,i+1,true,n,fee));
        }
        
        return dp[i][bought] = answer;
        
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        for(int i=0;i<=n;i++){
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        
        int ans = func(prices,0,true,n,fee);
        return ans;
        
    }
};