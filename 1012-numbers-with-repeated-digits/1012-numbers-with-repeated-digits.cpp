class Solution {
public:
    
    int dp[12][1<<11][2][2];
    
    int func(string &num,int n,int mask,bool tight,bool leading){
        
        if(n==0){
            return 1;
        }
        
        if(dp[n][mask][tight][leading]!=-1){
            return dp[n][mask][tight][leading];
        }
        
        int ans=0;
        
        int ub=tight ? num[num.length()-n]-'0' : 9;
        
        if(leading){
            
            ans+=func(num,n-1,mask,false,true);
            
            for(int dig=1;dig<=ub;dig++){
                
                if((mask&(1<<dig))==0)
                
                ans+=func(num,n-1,(mask|(1<<dig)),(tight&(ub==dig)),false);
                
            }
            
        }
        
        else{
            
            for(int dig=0;dig<=ub;dig++){
                
                if((mask&(1<<dig))==0)
                
                ans+=func(num,n-1,(mask|(1<<dig)),(tight&(ub==dig)),false);
                
            }
            
        }
        
        return dp[n][mask][tight][leading]=ans;
        
    }
    
    int numDupDigitsAtMostN(int n) {
        
        int m=n;
        
        memset(dp,-1,sizeof(dp));
        
        string s=to_string(n);
        
        n=s.length();
        
        int non_repeated=func(s,n,0,true,true);
        
       // cout<<non_repeated<<"\n";
        
        non_repeated--;
        
        return (m-non_repeated);
        
    }
};