class Solution {
public:
   
     int dp[12][1<<10][2][2];
    
    int func(string &num,int n,int mask,bool tight,bool leading){
        
        if(n==0){
            
            return 1;
            
        }
        
        if(dp[n][mask][tight][leading]!=-1){
            
            return dp[n][mask][tight][leading];
            
        }
        
        
        int ans=0;
        
        int ub=tight ? (num[num.length()-n]-'0') : 9;
        
        if(leading==true){
            
            ans+=func(num,n-1,mask,false,leading);
            
            for(int dig=1;dig<=ub;dig++){
                
                if((mask&(1<<dig))==0){
                    
                    ans+=func(num,n-1,(mask|(1<<dig)),(tight&(dig==ub)),false);
                    
                }
                
            }
            
        }
        
        else{
            
            for(int dig=0;dig<=ub;dig++){
            
                if(((mask&(1<<dig))==0)){

                    int nmask=mask;
                    nmask|=(1<<dig);

                    ans+=func(num,n-1,nmask,(tight&(dig==ub)),false);

                }
            
           }
            
        }

        
        return dp[n][mask][tight][leading] = ans;
        
    }
    
    int countSpecialNumbers(int n) {
        
        if(n<10){
            return n;
        }
        
        string s=to_string(n);
        
        n=s.length();
        
        memset(dp,-1,sizeof(dp));
        
        int ans=func(s,n,0,true,true);
        
        return (ans-1);
        
    }
};