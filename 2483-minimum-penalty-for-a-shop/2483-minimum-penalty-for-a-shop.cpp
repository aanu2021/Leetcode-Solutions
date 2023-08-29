class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.length();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        for(int i=0;i<n;i++){
            if(i) prefix[i] = prefix[i-1];
            prefix[i] += (s[i]=='N');
        }
        for(int i=n-1;i>=0;i--){
            if(i != n-1) suffix[i] = suffix[i+1];
            suffix[i] += (s[i]=='Y');
        }
        int mini = suffix[0];
        int minTime = 0;
        for(int i=0;i<n;i++){
            int current = prefix[i] + (i+1 < n ? suffix[i+1] : 0);
            if(mini > current){
                mini = current;
                minTime = i+1;
            }
        }
        return minTime;
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
