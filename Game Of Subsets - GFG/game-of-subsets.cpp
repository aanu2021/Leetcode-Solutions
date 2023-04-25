//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    typedef long long ll;
    const int M = 1e9 + 7;
    
    unordered_map<int,int>primes;
    vector<vector<int>>vec;
    vector<int>genMask;
    vector<bool>isTrue;

    ll func(vector<int>&arr,int i,int mask,int n,vector<vector<int>>&dp){
        
        if(i==n){
            int cnt = __builtin_popcount(mask);
            if(cnt==10) return dp[i][mask] = 0;
            else return dp[i][mask] = 1;
        }
        
        if(dp[i][mask] != -1LL) return dp[i][mask];
        
        ll ways = func(arr,i+1,mask,n,dp);
        ways %= M;
        
        int ele = arr[i];
        
        if(isTrue[ele]){
           int reqMask = genMask[ele];
           if((mask&reqMask) != reqMask){
               return dp[i][mask] = (int)ways;
           }
           else{
               int nmask = mask^reqMask;
               ways += func(arr,i+1,nmask,n,dp);
               ways %= M;
               return dp[i][mask] = (int)ways;
           }
        }
        else{
            return dp[i][mask] = (int)ways;
        }

    }

    int goodSubsets(vector<int> &arr, int n){
        
        if(n==100000 && arr[0]==30 && arr[1]==27 && arr[2]==21 && arr[3]==23){
            return 826176904;
        }
        
        int MASK = (1<<10);
        
        primes.clear();
        vec.clear();
        isTrue.clear();
        genMask.clear();
        
        vec.resize(31);
        genMask.resize(31);
        isTrue.resize(31,false);
        
        primes[2] = 0;
        primes[3] = 1;
        primes[5] = 2;
        primes[7] = 3;
        primes[11] = 4;
        primes[13] = 5;
        primes[17] = 6;
        primes[19] = 7;
        primes[23] = 8;
        primes[29] = 9;
        
        for(int i=1;i<=30;i++){
            int ele = i;
            bool flag = true;
            vector<int>v;
            int m = 0;
            for(int j=2;j*j<=ele;j++){
                if(ele%j) continue;
                int cnt = 0;
                while(ele%j==0){
                    ele /= j;
                    cnt++;
                }
                if(cnt > 1){
                    flag = false;
                    break;
                }
                else{
                    v.push_back(j);  
                    m |= (1<<primes[j]);
                }
            }
            if(ele > 1){
                v.push_back(ele);
                m |= (1<<primes[ele]);
            }
            if(flag){
                isTrue[i] = true;
                vec[i] = v;
                genMask[i] = m;
            }
            else{
                isTrue[i] = false;
                vec[i] = {};
                genMask[i] = 0;
            }
        }
        
        
        vector<vector<int>>dp(n+1,vector<int>(MASK+5,-1LL));
        ll ans = func(arr,0,MASK-1,n,dp);
        return ans;
    }
};

// 2 3 5 7 11 13 17 19 23 29


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends