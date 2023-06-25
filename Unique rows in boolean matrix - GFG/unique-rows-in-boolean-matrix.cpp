//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    
    typedef long long ll;
    
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>>answer;
        
        unordered_set<ll>visited;
        
        for(int i=0;i<row;i++){
            ll currMask = 0LL;
            vector<int>vec;
            for(int j=0;j<col;j++){
                if(M[i][j]){
                   currMask |= (1LL<<j);   
                }
                vec.push_back(M[i][j]);
            }
            if(visited.find(currMask) != visited.end()){
                continue;
            }
            else{
                answer.push_back(vec);
                visited.insert(currMask);
            }
        }
        
        return answer;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends