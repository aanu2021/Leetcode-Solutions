//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    int maxIntersections(vector<vector<int>> lines, int N) {
       map<int,int>freq;
       for(int i=0;i<N;i++){
           int x = lines[i][0];
           int y = lines[i][1];
           freq[x]++;
           freq[y+1]--;
       }
       int cnt = 0, maxi = 0;
       for(auto &itr : freq){
           cnt += itr.second;
           maxi = max(maxi,cnt);
       }
       return maxi;
    }
};



// [1,2] [1,3] [2,3] [4,4]
  



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