//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {

  public:
  
    typedef long long ll;
    
    const ll M = 1e9 + 7;
  
    int getSum(int x, int y, int z) {
        
        ll en[x+1][y+1][z+1];
        ll es[x+1][y+1][z+1];
        
        memset(en,0LL,sizeof(en));
        memset(es,0LL,sizeof(es));
        
        en[0][0][0] = 1LL;
        
        // en[i][j][k] --> denotes total numbers having exactly i 4's j 5's k 6's
        // es[i][j][k] --> denotes the sum of all the numbers having exactly .......
        
        ll ans = 0LL;
        
        for(int i=0;i<=x;i++){
            
            for(int j=0;j<=y;j++){
                
                for(int k=0;k<=z;k++){
                    
                    if(i>0){
                        
                        es[i][j][k] += (10LL*es[i-1][j][k] + 4LL*en[i-1][j][k]);
                        es[i][j][k] %= M;
                        en[i][j][k] += en[i-1][j][k];
                        en[i][j][k] %= M;
                        
                    }
                    
                    if(j>0){
                        
                        es[i][j][k] += (10LL*es[i][j-1][k] + 5LL*en[i][j-1][k]);
                        es[i][j][k] %= M;
                        en[i][j][k] += en[i][j-1][k];
                        en[i][j][k] %= M;
                        
                    }
                    
                    if(k>0){
                        
                        es[i][j][k] += (10LL*es[i][j][k-1] + 6LL*en[i][j][k-1]);
                        es[i][j][k] %= M;
                        en[i][j][k] += en[i][j][k-1];
                        en[i][j][k] %= M;
                        
                    }
                    
                    ans += es[i][j][k];
                    ans %= M;
                    
                }
                
            }
            
        }
        
        return ans%M;
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        Solution ob;
        cout << ob.getSum(x, y, z) << "\n";
    }
    return 0;
}

// } Driver Code Ends