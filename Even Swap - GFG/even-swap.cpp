//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &arr,int n)
        {
            for(int i=0;i<n;i++){
                
                int j = i;
                while(j < n && arr[j]%2 == arr[i]%2){
                    j++;
                }
                
                sort(arr.begin()+i,arr.begin()+j);
                reverse(arr.begin()+i,arr.begin()+j);
                
                i = j;
                i--;
            }
            return arr;
        }
};

/*

odd + odd   -> even
even + even -> even

odd, even
even, odd

restriction to swap two adjacent elements.

[odd.....odd] [even......even] [odd......odd] [even.......even]

*/


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends