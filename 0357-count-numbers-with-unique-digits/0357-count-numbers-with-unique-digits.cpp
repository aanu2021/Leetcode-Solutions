class Solution {
public:
    
    int dp[10][1024][2][2];
    
    int func(string &num,int n,int mask,bool leading,bool tight){
        
        if(n==0) return 1;
        
        if(dp[n][mask][leading][tight]!=-1) return dp[n][mask][leading][tight];
        
        int ans = 0;
        
        int ub = (tight ? num[num.length()-n]-'0' : 9);
        
        if(leading){
            
            ans += func(num,n-1,mask,true,false);
            
            for(int dig=1;dig<=ub;dig++){
                
                ans += func(num,n-1,(mask|(1<<dig)),false,(tight&(dig==ub)));
                
            }
            
        }
        
        else{
            
             for(int dig=0;dig<=ub;dig++){
                
                if((mask&(1<<dig))) continue; 
                 
                ans += func(num,n-1,(mask|(1<<dig)),false,(tight&(dig==ub)));
                
            }
            
        }
        
        return dp[n][mask][leading][tight] = ans;
        
    }
    
    int countNumbersWithUniqueDigits(int n) {
        
        int m = pow(10,n);
        
        n = m-1;
        
        m = n;
        
        string num = to_string(n);
        
        n = num.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = func(num,n,0,true,true);
        
        return ans;
        
    }
};