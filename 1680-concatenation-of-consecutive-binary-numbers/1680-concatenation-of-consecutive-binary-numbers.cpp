class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    int concatenatedBinary(int n) {
        
        string str="";
    
        ll sum = 0LL;
        
        ll i = 1LL;
        
        while(i<=n){
            
            sum = ((sum << (1 + (int)log2(i)))%M + i) % M;
            
            i++;
            
        }
        
        return sum;
        
    }
};

// 11 100   
    
//     product = 8
    
//     sum = 12