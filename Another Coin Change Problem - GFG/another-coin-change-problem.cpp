//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    vector<vector<vector<int>>>dp;
    
    int func(vector<int>&coins,int i,int N,int K,int target){
        
        if(i==N){
            if(K==0 && target==0) return 1;
            else return 0;
        }
        
        if(K < 0 || target < 0) return 0;
        if(K==0 && target==0) return 1;
        if(dp[i][K][target] != -1) return dp[i][K][target];
        
        // skip
        
        int decision = func(coins,i+1,N,K,target);
        
        // pick
        
        if(coins[i] <= target && K > 0){
            decision = max(decision,func(coins,i,N,K-1,target-coins[i]));
        }
        
        return dp[i][K][target] = decision;
    }
    
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
       dp.clear();
       dp = vector<vector<vector<int>>>(N+1,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
       sort(coins.rbegin(),coins.rend());
       int ans = func(coins,0,N,K,target);
       return ans > 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends