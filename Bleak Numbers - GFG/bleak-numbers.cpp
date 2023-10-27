//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    for(int i=0;i<=30;i++){
	        int rest = n-i;
	        if(rest < 0) continue;
	        int bitCnt = __builtin_popcount(rest);
	        if(bitCnt != i) continue;
	        else{
	            return 0;
	        }
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends