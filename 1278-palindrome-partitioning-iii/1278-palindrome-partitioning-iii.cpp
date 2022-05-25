class Solution {
public:
    
    int dp[105][105][105];
    
    int calc(string s,int i,int j){
        
        int cnt=0;
        
        while(i<=j){
            cnt+=(s[i]!=s[j]);
            i++;
            j--;
        }
        
        return cnt;
        
    }
    
    int func(string s,int start,int end,int k){
        
        if(start>end){
            
            if(k==0){
                return 0;
            }
            
            else{
                return 1e9;
            }
            
        }
        
        if(k==1){
            
            return dp[start][end][k]=calc(s,start,end);
            
        }
        
        if(end-start+1==k){
            
            return dp[start][end][k]=0;
            
        }
        
        if(end-start+1<k){
            
            return dp[start][end][k]=1e9;
            
        }
        
        if(dp[start][end][k]!=-1){
            return dp[start][end][k];
        }
        
        
        int ans=1e9;
        
        for(int i=start;i<=end;i++){
            
            int a=func(s,start,i,1);
            int b=func(s,i+1,end,k-1);
            
            ans=min(ans,a+b);
            
        }
        
        return dp[start][end][k]=ans;
        
    }
    
    int palindromePartition(string s, int k) {
        
        int n=s.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(s,0,n-1,k);
        
        return ans;
        
    }
};