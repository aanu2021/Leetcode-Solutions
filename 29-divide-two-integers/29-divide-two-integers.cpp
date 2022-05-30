class Solution {
public:
    
    typedef long long ll;
    
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        
        if(dividend==INT_MAX && divisor==-1){
            return -dividend;
        }
        
        if(dividend==INT_MAX && divisor==1){
            return INT_MAX;
        }
        
        if(dividend==0){
            return 0;
        }
        
        ll a=abs(dividend);
        ll b=abs(divisor);
        
        int res=0;
        
        while(a-b>=0){
            
            ll x=0;
            
            while((ll)(a-((ll)b<<1LL<<x))>=0){
                x++;
            }
            
            res+=(1<<x);
            a-=(b<<x);
            
        }
        
        if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
            
            return res;
            
        }
        
        else{
            
            return -res;
            
        }   
           
    }
};