//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    typedef long long ll;
    vector<vector<int>>graph; 
    vector<int>cost;
  
    pair<ll,ll> dfs(int u,ll &maxScore){
        ll currScore = (ll)cost[u];
        // Leaf Node
        if(graph[u].size()==0){
            maxScore = max(maxScore,currScore);
            return {currScore,currScore};
        }
        // Non-Leaf Node
        else{
            ll minNbr = 1e18;
            ll maxNbr = -1e18;
            for(int nbr:graph[u]){
                auto nbrScore = dfs(nbr,maxScore);
                minNbr = min({minNbr,nbrScore.first,nbrScore.second});
                maxNbr = max({maxNbr,nbrScore.first,nbrScore.second});
            }
            ll currMax = currScore - minNbr;
            ll currMin = currScore - maxNbr;
            maxScore = max(maxScore,currMax);
            return {currMax,currMin};
        }
    }
  
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        
        graph.clear();
        graph.resize(N+1);
        cost.clear();
        cost.resize(N+1);
        
        for(int i=1;i<N;i++){
            graph[P[i]].push_back(i+1);
        }
        
        for(int i=0;i<N;i++){
            cost[i+1] = A[i];
        }
        
        ll maxScore = -1e18;
        dfs(1,maxScore);
        return maxScore;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends