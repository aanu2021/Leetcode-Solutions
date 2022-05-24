// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

   typedef long long ll;
   
   const ll M = 1003;
   
   ll mod(ll a){
       return ((a%M)+M)%M;
   }
   
   ll mul(ll a,ll b){
       return mod(mod(a)*mod(b));
   }
   
   ll add(ll a,ll b){
       return mod(mod(a)+mod(b));
   }

    int countWays(int N, string s){
        
        string s1="";
        string s2="";
        
        for(ll i=0;i<N;i+=2){
            s1+=s[i];
        }
        
        for(ll i=1;i<N;i+=2){
            s2+=s[i];
        }
        
        ll n=s1.length();
        
        vector<vector<ll>>truedp(n+1,vector<ll>(n+1,0LL));
        
        vector<vector<ll>>falsedp(n+1,vector<ll>(n+1,0LL));
        
        for(ll i=0;i<n;i++){
            truedp[i][i]=(s1[i]=='T' ? 1LL : 0LL);
            falsedp[i][i]=!truedp[i][i];
        }
        
        for(ll L=2;L<=n;L++){
            
            for(ll i=0;i<n-L+1;i++){
                
                ll j=i+L-1;
                
                ll ans1=0LL,ans2=0LL;
                
                for(ll k=i;k<j;k++){
                    
                    if(s2[k]=='|'){
                        
                        ll curr1=(truedp[i][k]*truedp[k+1][j])+(truedp[i][k]*falsedp[k+1][j])+(falsedp[i][k]*truedp[k+1][j]);
                        
                        ll curr2=(falsedp[i][k]*falsedp[k+1][j]);
                        
                        ans1=add(ans1,curr1);
                        ans2=add(ans2,curr2);
                        
                    }
                    
                    else if(s2[k]=='&'){
                        
                        ll curr2=(truedp[i][k]*falsedp[k+1][j])+(falsedp[i][k]*falsedp[k+1][j])+(falsedp[i][k]*truedp[k+1][j]);
                        
                        ll curr1=(truedp[i][k]*truedp[k+1][j]);
                        
                        ans1=add(ans1,curr1);
                        ans2=add(ans2,curr2);
                        
                    }
                    
                    else{
                        
                        ll curr1=(truedp[i][k]*falsedp[k+1][j])+(falsedp[i][k]*truedp[k+1][j]);
                        
                        ll curr2=(falsedp[i][k]*falsedp[k+1][j])+(truedp[i][k]*truedp[k+1][j]);
                        
                        ans1=add(ans1,curr1);
                        ans2=add(ans2,curr2);
                        
                    }
                    
                }
                
                truedp[i][j]=mod(ans1);
                falsedp[i][j]=mod(ans2);
                
            }
            
        }
        
        return mod(truedp[0][n-1]);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends