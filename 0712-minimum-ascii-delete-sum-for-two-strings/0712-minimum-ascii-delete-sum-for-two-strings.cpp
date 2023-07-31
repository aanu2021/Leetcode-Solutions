class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int m = s1.length();
        int n = s2.length();
        
        vector<int>prev(n+1, 0);
        vector<int>curr(n+1, 0);
        
        s1 = "#" + s1;
        s2 = "#" + s2;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i] == s2[j]){
                    curr[j] = (int)s1[i] + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        
        int totalSum = 0;
        for(int i=1;i<=m;i++){
            totalSum += (int)(s1[i]);
        }
        for(int j=1;j<=n;j++){
            totalSum += (int)(s2[j]);
        }
        
        totalSum -= (2*prev[n]);
        return totalSum;
        
    }
};