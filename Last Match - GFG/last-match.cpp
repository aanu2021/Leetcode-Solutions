//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string s,string p){
        int n = s.length();
        int m = p.length();
        if(n < m) return -1;
        vector<int>lps(m,0);
        for(int i=1;i<m;i++){
            int len = lps[i-1];
            while(len && p[len] != p[i]){
                len = lps[len-1];
            }
            if(p[len] == p[i]){
                len++;
            }
            lps[i] = len;
        }
        int j = 0;
        int lastIdx = -2;
        for(int i=0;i<n;i++){
            if(s[i]==p[j]){
                j++;
                if(j==m){
                    lastIdx = i-m+1;
                    // cout<<lastIdx<<"\n";
                    j = lps[j-1];
                }
            }
            else{
                while(j && s[i] != p[j]){
                    j = lps[j-1];
                }
                if(s[i] == p[j]){
                    j++;
                }
            }
        }
        return lastIdx + 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends