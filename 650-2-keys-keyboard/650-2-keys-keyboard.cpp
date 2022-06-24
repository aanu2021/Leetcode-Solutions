// CPPCPPPPCPP.......

// g1 , g2 ,  g3 , g4 , ..........

// gi=p*q --> (p+q)

// As p+q <= pq

// Ans is the number of prime factors of N --> O(sqrt(N)).


class Solution {
public:
    int minSteps(int n) {
        
        int ans=0;
        
        int d=2;
        
        while(n>1){
            
            while(n%d==0){
                
                ans+=d;
                
                n/=d;
                
            }
            
            d++;
            
        }
        
        return ans;
        
    }
};