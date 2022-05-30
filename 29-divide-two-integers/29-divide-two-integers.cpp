class Solution {
public:
    
    typedef long long ll;
    
    /*
    
     Here we use the concept of repeated subtraction , but instead of using modulo , we have to use bit Manipulation.
     
     e.g : A = 22  ,  B = 3
     
           Now we have to check how many times we can divide 
           A with B , like A-=B // 22-=3=19
           
           
           but the catch is that instead of subtracting , here we have to use left shift operator , to determine the number of times we can divide A by B.
           
           for these , we have to use a formulae , 
           
           ll x=0 , while(a-(b<<1<<x)>=0) x++;
           
           res+=(1<<x);
           
           a-=(b<<x);
    
    */
    
    int divide(int dividend, int divisor) {
        
        ll a=abs(dividend);
        ll b=abs(divisor);
        
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        if(dividend==0){
            return 0;
        }
        
        ll ans=0LL;
        
        while(a-b>=0){
            
            ll x=0LL;
            
            while((a-(b<<1<<x))>=0){
                x++;
            }
            
            ans+=(1<<x);
            
            a-=(b<<x);
            
        }
        
       if(dividend>0 && divisor>0 || dividend<0 && divisor<0){
            return ans;
        }else{
            return -ans;
        }
        
    }
};