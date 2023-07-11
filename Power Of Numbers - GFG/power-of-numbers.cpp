//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll Mod(ll a){
        return ((a%M) + M)%M;
    }
    ll mul(ll a,ll b){
        return Mod(Mod(a)*Mod(b));
    }
    ll add(ll a,ll b){
        return Mod(Mod(a)+Mod(b));
    }
    ll modPow(ll a,ll b){
        if(b==0) return 1LL;
        if(b==1) return a;
        ll res = 1LL;
        while(b){
            if(b%2) res = mul(res,a);
            b/=2;
            a = mul(a,a);
        }
        return res;
    }
    
    long long power(int N,int R)
    {
       
       return modPow((ll)N,(ll)R);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends