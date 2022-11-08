class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       
        if(n==0) return 1;
        if(n==1) return 10;
        
        int prod = 1;
        int cnt = 9;
        int sum = 10;
        
        for(int i=2;i<=n;i++){
            
            prod*=cnt;
            cnt--;
            
            sum += 9*prod;
            
        }
        return sum;
        
    }
};