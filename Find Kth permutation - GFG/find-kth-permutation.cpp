//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    void func(vector<int>&nums,vector<int>&fact,int n,int k,string &ans){
        
        if(n==1){
            ans += (char)(nums[0] + '0');
            return;
        }
        
        int idx = k/fact[n-1];
        
        ans += (char)(nums[idx] + '0');
        
        nums.erase(nums.begin() + idx);
        
        k -= (idx*fact[n-1]);
        
        func(nums,fact,n-1,k,ans);
        
    }

    string kthPermutation(int n, int k)
    {
        
        k--;
        
        string ans = "";
        
        vector<int>nums;
        vector<int>fact(n+1,0);
        
        fact[0] = 1;
        
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            fact[i] = fact[i-1]*i;
        }
        
        func(nums,fact,n,k,ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends