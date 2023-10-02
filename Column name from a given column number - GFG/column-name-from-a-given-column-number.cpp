//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res = "";
        while(n > 0){
            n--;
            long long int rem = (n%26);
            res += (char)(rem+'A');
            n /= 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

/*

n = c1*26^0 + c2*26^1 + c3*26^2 + .... 

n = c1 + 26*(M)

n%26 = c1%26 + 0

n%26 = c1

*/


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends