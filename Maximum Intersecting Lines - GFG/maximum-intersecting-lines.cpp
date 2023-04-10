//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        vector<int>X;
        vector<int>Y;
        for(int i=0;i<N;i++){
            X.push_back(lines[i][0]);
            Y.push_back(lines[i][1]);
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        int cnt = 0, maxi = 0;
        int i = 0,j = 0;
        while(i<N && j<N){
            if(X[i] <= Y[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends