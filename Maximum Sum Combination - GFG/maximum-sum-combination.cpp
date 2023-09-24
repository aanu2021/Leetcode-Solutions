//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Pair{
    int i;
    int j;
    int sum;
};

struct comp{
  bool operator()(const Pair&x,const Pair&y){
      return x.sum < y.sum;
  }  
};

class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        priority_queue<Pair,vector<Pair>,comp>pq;
        unordered_map<int,unordered_map<int,int>>visited;
        pq.push({0,0,A[0]+B[0]});
        visited[0][0] = 1;
        vector<int>answer;
        while(!pq.empty() && k>0){
            auto curr = pq.top(); pq.pop();
            int i = curr.i;
            int j = curr.j;
            int sum = curr.sum;
            answer.push_back(sum);
            k--;
            if(i+1<n && j<n){
                if(visited.find(i+1) == visited.end() || visited[i+1].find(j) == visited[i+1].end()){
                    pq.push({i+1,j,A[i+1]+B[j]});
                    visited[i+1][j] = 1;
                }
            }
            if(i<n && j+1<n){
                if(visited.find(i) == visited.end() || visited[i].find(j+1) == visited[i].end()){
                    pq.push({i,j+1,A[i]+B[j+1]});
                    visited[i][j+1] = 1;
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends