//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int currSum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            currSum += A[i];
            if(mp.find(currSum) != mp.end()){
                maxLen = max(maxLen, i - mp[currSum]);
            }
            else{
                mp[currSum] = i;
            }
        }
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends