//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(S==0){
            if(N==1) return "0";
            else return "-1";
        }
        if(S > (9*N)) return "-1";
        string res(N,'0');
        for(int i=0;i<N;i++){
            int current = min(S,9);
            S -= current;
            res[i] = (char)(current+'0');
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends