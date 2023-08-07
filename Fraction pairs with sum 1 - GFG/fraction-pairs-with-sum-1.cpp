//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        int answer = 0;
        unordered_map<int,unordered_map<int,int>>freq;
        for(int i=0;i<n;i++){
            int num = numerator[i];
            int den = denominator[i];
            int g = __gcd(num,den);
            num/=g;
            den/=g;
            int req = den - num;
            answer += freq[req][den];
            freq[num][den]++;
        }
        return answer;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends