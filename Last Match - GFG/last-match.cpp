//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string A,string B){
        int m = A.length();
        int n = B.length();
        if(m < n) return -1;
        vector<int>lps(n,0);
        for(int i=1;i<n;i++){
            int len = lps[i-1];
            while(len > 0 && B[len] != B[i]){
                len = lps[len-1];
            }
            if(B[len] == B[i]){
                len++;
            }
            lps[i] = len;
        }
        int j = 0, lastIdx = -2;
        for(int i=0;i<m;i++){
            if(A[i] == B[j]){
                j++;
                if(j==n){
                    lastIdx = i-j+1;
                    j = lps[j-1];
                }
            }
            else{
                while(j && A[i] != B[j]){
                    j = lps[j-1];
                }
                if(A[i] == B[j]){
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