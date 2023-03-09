//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    typedef long long int ll;

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        ll costR = (ll)r[0];
        ll costG = (ll)g[0];
        ll costB = (ll)b[0];
        for(int i=1;i<N;i++){
            ll nCostR = (ll)r[i] + min(costG,costB);
            ll nCostG = (ll)g[i] + min(costR,costB);
            ll nCostB = (ll)b[i] + min(costR,costG);
            costR = nCostR;
            costG = nCostG;
            costB = nCostB;
        }
        return min({costR,costG,costB});
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends