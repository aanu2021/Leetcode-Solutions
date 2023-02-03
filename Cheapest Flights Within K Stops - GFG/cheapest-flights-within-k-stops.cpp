//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<int>price(n,1e9);
        vector<int>tempPrice(n,1e9);
        price[src] = 0;
        tempPrice[src] = 0;
        k++;
        for(int i=0;i<k;i++){
            for(int j=0;j<flights.size();j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                if(tempPrice[v] > price[u] + wt){
                    tempPrice[v] = price[u] + wt;
                }
            }
            for(int j=0;j<n;j++){
                price[j] = tempPrice[j];
            }
        }
        if(price[dst] >= 1e9) return -1;
        else return price[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends