//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int c1 = 0;
        for(int i=0;i<n;i++){
            if(a[i]==1) c1++;
        }
        int currSum = 0,maxSum = 0;
        for(int i=0;i<n;i++){
            if(a[i]==0) currSum++;
            else currSum--;
            if(currSum < 0){
                currSum = 0;
            }
            maxSum = max(maxSum, currSum);
        }
        return c1 + maxSum;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends