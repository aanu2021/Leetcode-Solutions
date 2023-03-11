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
        for(int i=0;i<q;i++){
            int L = Q[i][0];
            int R = Q[i][1];
            int K = Q[i][2];
            int cnt = 0;
            for(int j=L;j<=R;j++){
                if(freq_suf[j] == K) cnt++;
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