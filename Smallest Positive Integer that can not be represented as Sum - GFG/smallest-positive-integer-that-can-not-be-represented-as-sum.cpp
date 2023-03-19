//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:

    typedef long long ll;

    long long smallestpositive(vector<long long> arr, int n)
    { 
        sort(arr.begin(),arr.end());
        ll sum = 1LL;
        for(int i=0;i<n && arr[i] <= sum;i++){
            sum += arr[i];
        }
        return sum;
        
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
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 

// } Driver Code Ends