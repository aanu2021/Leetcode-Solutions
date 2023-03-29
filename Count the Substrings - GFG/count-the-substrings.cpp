//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        int n = s.length();
        int currSum = 0;
        unordered_map<int,int>freq;
        freq[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z') currSum++;
            else currSum--;
            ans += freq[currSum];
            freq[currSum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends