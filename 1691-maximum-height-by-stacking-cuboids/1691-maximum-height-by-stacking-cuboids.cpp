class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[0] + x[1] + x[2] > y[0] + y[1] + y[2];
    }
    
    int maxHeight(vector<vector<int>>& c) {
        
        int n = c.size();
        
        for(int i=0;i<n;i++){
            sort(c[i].begin(),c[i].end());
        }
        
        sort(c.begin(),c.end(),comp);
        
        vector<int>dp(n,0);
        
        dp[0] = c[0][2];
        
        for(int i=1;i<n;i++){
            int maxHeight = 0;
            for(int j=0;j<i;j++){
                if(c[i][0] <= c[j][0] && c[i][1] <= c[j][1] && c[i][2] <= c[j][2]){
                    maxHeight = max(maxHeight, dp[j]);
                }
            }
            dp[i] = maxHeight + c[i][2];
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};

/*

A1 A2 A3  (A1 <= A2 <= A3)
B1 B2 B3  (B1 <= B2 <= B3)

A1 + A2 + A3 > B1 + B2 + B3

A1 <= B1
A2 <= B2
A3 <= B3

A1 > B1
A2 > B1
A3 > B1

A2 > B2
A3 > B2

A3 > B3
A3 > B2
A3 > B1


width, length, height

width, length -> base
height -> deciding factor

 C[i]                 C[j]
 w[i] l[i] h[i]       w[j] l[j] h[j]
 
 w[i] <= w[j]
 l[i] <= l[j]
 h[i] <= h[j]
    
    
 3 5
 5   
 
 */