//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
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
  
    long long findMaxSubsetSum(int N, vector<int> &A) {
        
        vector<ll>dp(N,-1e18);
        
        dp[0] = (ll)A[0];
        
        for(int i=1;i<N;i++){
            dp[i] = dp[i-1] + A[i];
            if(i-2 >= 0){
                dp[i] = max(dp[i],dp[i-2] + (ll)A[i]);
            }
            else{
                dp[i] = max(dp[i],(ll)A[i]);
            }
        }
        
        return max(dp[N-1],dp[N-2]);
        
    }
};

// a0 a1 a2 a3 a4



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends