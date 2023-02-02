//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    string topoSort(int n,vector<set<int>>&graph){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                indegree[j]++;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<indegree[i]<<" ";
        // }cout<<"\n";
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += (char)(node+'a');
            for(int nbr:graph[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        // cout<<ans<<"\n";
        return ans;
    }
    
    string findOrder(string dict[], int n, int k) {
        
        vector<set<int>>graph(k);
        
        for(int i=0;i<n-1;i++){
            int len1 = dict[i].length();
            int len2 = dict[i+1].length();
            int len = min(len1,len2);
            for(int j=0;j<len;j++){
                if(dict[i][j] != dict[i+1][j]){
                    graph[dict[i][j]-'a'].insert(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        string ans = topoSort(k,graph);
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends