//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) {
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int num_moves = 0;
        for(int i=0;i<n;i++){
            num_moves += abs(chairs[i]-passengers[i]);
        }
        return num_moves;
    }
};

/*

1 3 5
2 4 7

1 + 1 + 2 = 4

2 2 6 6
1 2 3 6

1 + 0 + 3 + 0 = 4

*/


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val : chairs) cin >> val;
        for (auto &val : passengers) cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends