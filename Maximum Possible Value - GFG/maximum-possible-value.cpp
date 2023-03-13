//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    typedef long long ll; 
  
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        ll cost = 0LL;
        ll totalNum = 0LL;
        ll currSum = 0LL;
        ll mini = 1e18;
        for(int i=0;i<N;i++){
            ll curr = (ll)(B[i]/2);
            totalNum += curr;
            currSum += (2LL*curr*(ll)A[i]);
            B[i] -= curr*2LL;
            if(curr > 0){
                mini = min(mini,(ll)A[i]);
            }
        }
        if(totalNum%2==0){
            return currSum;
        }
        else{
            return currSum - (2LL*mini);
        }
        
    }
};

// 5 3
// 2 1

// 2 3
// 2 5

// square = 1 + 1 + 1 + 1 = (1 + 1) + (1 + 1)

// rectangle = 1 + 1 + 0 + 0 

// 3 4 6 5

// 2 3 1 6

// 1 1 0 3

// 30 + 8





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends