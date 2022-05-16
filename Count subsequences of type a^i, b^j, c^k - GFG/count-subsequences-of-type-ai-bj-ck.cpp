// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    
    int fun(string &s) {
        
        ll n=s.length();
        
        ll a=0LL;
        ll b=0LL;
        ll c=0LL;
        
        for(ll i=0;i<n;i++){
            
            if(s[i]=='a'){
                
                a=add(mul(2LL,a),1LL);
                
            }
            
            else if(s[i]=='b'){
                
                b=add(a,mul(2LL,b));
                
            }
            
            else{
                
                c=add(b,mul(2LL,c));
                
            }
            
        }
        
        return mod(c);
        
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends