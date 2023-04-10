//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        set<int>points;
        for(int i=0;i<N;i++){
            points.insert(lines[i][0]);
            points.insert(lines[i][1]);
        }
        vector<int>vec;
        for(auto itr : points){
            vec.push_back(itr);
        }
        unordered_map<int,int>mp;
        int ptr = 0;
        for(int i=0;i<vec.size();i++){
            mp[vec[i]] = ptr++;
        }
        vector<int>prefix(ptr+5,0);
        for(int i=0;i<N;i++){
            int a = mp[lines[i][0]];
            int b = mp[lines[i][1]];
            prefix[a]++;
            prefix[b+1]--;
        }
        for(int i=1;i<ptr;i++){
            prefix[i] += prefix[i-1];
        }
        return *max_element(prefix.begin(),prefix.end());
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