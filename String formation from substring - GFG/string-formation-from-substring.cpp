//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n = s.length();
	    vector<int>lps(n,0);
	    for(int i=1;i<n;i++){
	        int len = lps[i-1];
	        while(len>0 && s[len]!=s[i]){
	            len = lps[len-1];
	        }
	        if(s[i]==s[len]) len++;
	        lps[i] = len;
	    }
	    if(lps[n-1]>0 && (lps[n-1]%(n-lps[n-1]))==0) return true;
	    else return false;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends