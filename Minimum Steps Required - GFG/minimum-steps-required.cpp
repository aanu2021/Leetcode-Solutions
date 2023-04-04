//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    
    int n = str.length();
    int c1 = 0;
    int c2 = 0;
    for(int i=0;i<n;i++){
        if(str[i]=='a') c1++;
        else          c2++;
        int j = i;
        while(j < n && str[j]==str[i]){
            j++;
        }
        i = j;
        i--;
    }
    return min(c1,c2) + 1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends