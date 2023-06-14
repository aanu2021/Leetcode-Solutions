//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    typedef long long ll; 
  
    long long maxDiamonds(int A[], int N, int K) {
       
        ll sum = 0LL;
        
        priority_queue<int>pq;
        
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        
        while(!pq.empty() && K > 0){
            int ele = pq.top(); pq.pop();
            sum += (ll)(ele);
            if((ele/2) > 0){
                pq.push(ele/2);
            }
            K--;
        }
        
        return sum;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends