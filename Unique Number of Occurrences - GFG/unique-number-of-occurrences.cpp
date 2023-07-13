//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        vector<int>freq_arr(n+1,0);
        unordered_map<int,int>freq;
        
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(auto &itr : freq){
            freq_arr[itr.second]++;
        }
        for(int i=1;i<=n;i++){
            if(freq_arr[i] > 1){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends