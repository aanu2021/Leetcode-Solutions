//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int q, vector<int> &A, vector<vector<int>> &Q) {
        vector<int>answer;
        vector<int>freq_suf(n,0);
        unordered_map<int,int>freq;
        for(int i=n-1;i>=0;i--){
            freq[A[i]]++;
            freq_suf[i] = freq[A[i]];
        }
        vector<vector<int>>prec(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            prec[freq_suf[i]][i+1]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                prec[i][j] += prec[i][j-1];
            }
        }
        for(int i=0;i<q;i++){
            int L = Q[i][0];
            int R = Q[i][1];
            int K = Q[i][2];
            int cnt = 0;
            if(K > n || K < 1){
                cnt = 0;
            }
            else{
                cnt = prec[K][R+1] - prec[K][L]; 
            }
            answer.push_back(cnt);
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends