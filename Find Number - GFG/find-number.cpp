//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    typedef long long ll;

    long long findNumber(long long N){
        
        string str = "";
        char dig[5] = {'1','3','5','7','9'};
        ll mul = 5LL , pre = 1LL;
        while(N > 0){
           ll rem = (N%mul)-1;
           ll id = (rem+mul)%mul;
           ll idx = id/pre;
           str += dig[idx];
           N -= mul;
           mul*=5LL;
           pre*=5LL;
        }
        reverse(str.begin(),str.end());
        return stoll(str);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends