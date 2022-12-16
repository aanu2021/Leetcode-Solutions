//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string s,string p){
        int n = s.length();
        int m = p.length();
        vector<int>lps(m,0);
        for(int i=1;i<m;i++){
            int len = lps[i-1];
            while(len>0 && p[len]!=p[i]){
                len = lps[len-1];
            }
            if(p[len]==p[i]) len++;
            lps[i] = len;
        }
        int idx = -2;
        int j = 0;
        for(int i=0;i<n;i++){
            if(s[i]==p[j]){
                j++;
            }
            else{
                while(j>0 && s[i]!=p[j]){
                    j = lps[j-1];
                }
                if(s[i]==p[j]) j++;
            }
            if(j==m){
                idx = i-j+1;
                j = lps[j-1];
            }
        }
        return idx + 1;
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