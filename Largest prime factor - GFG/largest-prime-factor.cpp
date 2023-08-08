//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 

    typedef long long int ll;

    long long int largestPrimeFactor(int N){
        if(N==2 || N==3) return N;
        ll i = 2LL;
        ll largest = -1LL;
        while(i*i<=N){
            while(N%i==0){
                largest = max(largest,i);
                N/=i;
            }
            i++;
        }
        if(N > 1){
            largest = max(largest,(ll)N);
        }
        return largest;
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
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends