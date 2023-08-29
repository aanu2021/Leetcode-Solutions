class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.length();
        int suffixSum = 0;
        int prefixSum = 0;
        int minTime = n+1;
        int timer = 0;
        for(int i=n-1;i>=0;i--){
            suffixSum += (s[i]=='Y');
        }
        minTime = suffixSum;
        timer = 0;
        for(int i=0;i<n;i++){
            suffixSum -= (s[i]=='Y');
            prefixSum += (s[i]=='N');
            int currSum = prefixSum + suffixSum;
            if(currSum < minTime){
                minTime = currSum;
                timer = i+1;
            }
        }
        return timer;
    }
};

/*

Y -> customers come at the i-th hour
N -> no customers come at the i-th hour

shop closes at j-th hour

shop = open    customer = yes   ->   0 penalty
shop = open    customer = no    ->   1 penalty
shop = close   customer = yes   ->   1 penalty
shop = close   customer = no    ->   0 penalty

*/
