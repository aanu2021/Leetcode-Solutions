//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

typedef long long ll;
const ll M = 1e9 + 7;

class Solution{   
public:

    int countPaths(int N){
        
        if(N==1) return 0;
        if(N==2) return 3;
        ll o = 3LL , a = 2LL , b = 2LL , c = 2LL;
        
        for(int i=3;i<=N;i++){
            
            ll no = 0LL , na = 0LL , nb = 0LL , nc = 0LL;
            
            // starting from O
            
            no += a;
            no %= M;
            no += b;
            no %= M;
            no += c;
            no %= M;
            
            // starting from A
            
            na += o;
            na %= M;
            na += b;
            na %= M;
            na += c;
            na %= M;
            
            // starting from B
            
            nb += o;
            nb %= M;
            nb += a;
            nb %= M;
            nb += c;
            nb %= M;
            
            // starting from C
            
            nc += o;
            nc %= M;
            nc += a;
            nc %= M;
            nc += b;
            nc %= M;
            
            o = no;
            a = na;
            b = nb;
            c = nc;
  
        }
        
        return o;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends