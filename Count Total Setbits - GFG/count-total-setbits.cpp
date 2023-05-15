//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    typedef long long ll; 
  
    ll findLargestPower(ll n)
    {
        ll x = 0;
        while ((1LL << x) <= n)
            x++;
        return x - 1;
    }
     
    ll countSetBits(ll n)
    {
        if (n <= 1)
            return n;
        ll x = findLargestPower(n);
        return (x * pow(2LL, (x - 1))) + (n - pow(2LL, x) + 1LL)
               + countSetBits(n - pow(2LL, x));
    }
  
    long long countBits(long long N) {
        return countSetBits(N);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends