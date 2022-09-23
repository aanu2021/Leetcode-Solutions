class Solution {
public:
    
    typedef long long ll;
    
    ll M = 1e9 + 7;
    
    int concatenatedBinary(int n) {
        
        string str="";
    
        ll product = 1LL;
        
        ll sum = 0LL;
        
        for(int i=n;i>=1;--i){
            
            int msb=log2(i);
            
            for(int bit=0;bit<=msb;bit++){
                
                if((i&(1<<bit))){
                    
                    sum=((sum%M)+(product%M))%M;
                    
                }
                
                product=((2LL%M)*(product%M))%M;
                
            }
            
        }

        
        return sum;
        
    }
};

// 11 100   
    
//     product = 8
    
//     sum = 12