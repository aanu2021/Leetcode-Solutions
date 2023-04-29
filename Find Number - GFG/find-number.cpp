//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    typedef long long ll;

    ll dp[20][2][2];

    ll func(string &num,int n,bool leading,bool tight){
        if(n==0) return 1LL;
        if(dp[n][leading][tight] != -1) return dp[n][leading][tight];
        ll ways = 0LL;
        if(leading){
            ways += func(num,n-1,leading,false);
            ll ub = (tight ? num[num.length()-n]-'0' : 9LL);
            for(ll dig=1;dig<=ub;dig++){
                if(dig%2==0) continue;
                ways += func(num,n-1,false,(tight&(ub==dig)));
            }
            return dp[n][leading][tight] = ways;
        }
        else{
            ll ub = (tight ? num[num.length()-n]-'0' : 9LL);
            for(ll dig=1;dig<=ub;dig++){
                if(dig%2==0) continue;
                ways += func(num,n-1,false,(tight&(ub==dig)));
            }
            return dp[n][leading][tight] = ways;
        }
    }

    ll getNum(ll number){
        string num = to_string(number);
        memset(dp,-1,sizeof(dp));
        ll ans = func(num,num.length(),true,true);
        return ans - 1LL;
    }

    long long findNumber(long long N){
        
        ll low = 1LL, high = 10000000000000000;
        ll ans = -1LL;
        while(low <= high){
            ll mid = low + (high-low)/2;
            ll currSum = getNum(mid);
            if(currSum >= N){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
        
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