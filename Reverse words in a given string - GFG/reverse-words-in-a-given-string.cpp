//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverseSubstring(string &s,int l,int r){
        while(l < r){
            swap(s[l++],s[r--]);
        }
    }
    string reverseWords(string s) 
    { 
       int n = s.length();
       reverse(s.begin(),s.end());
       for(int i=0;i<n;i++){
           if(s[i]=='.') continue;
           int j = i;
           while(j<n && s[j]!='.'){
               j++;
           }
           reverseSubstring(s,i,j-1);
           i = j;
           i--;
       }
       return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends