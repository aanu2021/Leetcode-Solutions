//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<int>answer(N,0);
            vector<vector<int>>prefix(N+1,vector<int>(22,0));
            for(int i=0;i<Q;i++){
                int l = U[i][0];
                int r = U[i][1];
                int x = U[i][2];
                l--; r--;
                for(int j=0;j<22;j++){
                    if((x&(1<<j))){
                        prefix[l][j]++;
                        prefix[r+1][j]--;
                    }
                }
            }
            for(int i=1;i<N;i++){
                for(int j=0;j<22;j++){
                    prefix[i][j] += prefix[i-1][j];
                }
            }
            for(int i=0;i<N;i++){
                int currValue = 0;
                for(int j=0;j<22;j++){
                    if(prefix[i][j]) currValue |= (1<<j);
                }
                answer[i] = (currValue);
            }
            return answer;
        }
};





//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends