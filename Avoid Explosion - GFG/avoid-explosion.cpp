//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU{
  
  vector<int>Parent;
  vector<int>Rank;
  
  public:
  
  DSU(int n){
      Parent.resize(n+1);
      Rank.resize(n+1);
      for(int i=1;i<=n;i++){
          Parent[i] = i;
          Rank[i] = 1;
      }
  }
  
  int find(int x){
      if(Parent[x]==x) return x;
      return Parent[x] = find(Parent[x]);
  }
  
  void Union(int x,int y){
      int lx = find(x);
      int ly = find(y);
      if(lx != ly){
          if(Rank[lx] > Rank[ly]){
              Parent[ly] = lx;
          }
          else{
              Parent[lx] = ly;
              if(Rank[lx]==Rank[ly]) Rank[lx]++;
          }
      }
  }
    
};

class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,
                                  vector<vector<int>> danger, int m)
    {
        
        vector<string>ans;
        DSU obj(n);
        for(int i=0;i<n;i++){
            int m1 = mix[i][0];
            int m2 = mix[i][1];
            bool flag = true;
            int p1 = obj.find(m1);
            int p2 = obj.find(m2);
            for(int j=0;j<m;j++){
                int d1 = danger[j][0];
                int d2 = danger[j][1];
                int pd1 = obj.find(d1);
                int pd2 = obj.find(d2);
                if((p1==pd1 && p2==pd2) || (p1==pd2 && p2==pd1)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back("Yes");
                obj.Union(p1,p2);
            }else{
                ans.push_back("No");
            }
        }
        return ans;
        
    }                                  
};

/*

1 2 
2 3
4 5
3 5
2 4

1 3
2 4


1 2

*/


//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends