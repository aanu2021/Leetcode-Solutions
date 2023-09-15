//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    long long countWays(int n)
    {
        
        if(n==1 || n==2) return n;
        if(n==3) return 4LL;
        
        ll a = 1LL, b = 2LL, c = 4LL;
        
        for(int i=4;i<=n;i++){
            ll temp = (a+b+c)%M;
            a = b;
            b = c;
            c = temp;
        }
        return c;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends