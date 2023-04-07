//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        
        int n = str.length();
        string temp = str;
        reverse(temp.begin(),temp.end());
        str += "*";
        str += temp;
        int m = n;
        n = str.length();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            while(len > 0 && str[len] != str[i]){
                len = lps[len-1];
            }
            if(str[len]==str[i]) len++;
            lps[i] = len;
        }
        return (m-lps[n-1]);
        
    }
};

// A B A * A B A
// 0 0 1 0 1 2 3


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends