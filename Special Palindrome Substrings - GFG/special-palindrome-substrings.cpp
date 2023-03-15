//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int func(string s1,string s2,int l,int m,int n){
        
        string temp = s1;
        
        int r = (l+n-1);
        int k = 0,ops = 0;
        
        for(int i=l;i<=r;i++){
            s1[i] = s2[k++];
        }
        
        for(int i=0;i<m;i++){
            int j = (m-i-1);
            if(i>=l && i<=r){
                if(j>=l && j<=r){
                    if(s1[i] != s1[j]) return 1e9;
                }
                else{
                    s1[j] = s1[i];
                }
            }
            else{
                if(s1[i] != s1[j]){
                    s1[i] = s1[j];
                }
            }
        }
        
        for(int i=0;i<m;i++){
            if(s1[i] != temp[i]) ops++;
        }
        
        return ops;
        
    }
    
    int specialPalindrome(string s1, string s2){
    
       int m = s1.length();
       int n = s2.length();
       
       int minOps = 1e9;
       
       for(int i=0;i<=m-n;i++){
           int currOps = func(s1,s2,i,m,n);
           minOps = min(minOps,currOps);
       }
       
       return minOps >= 1e9 ? -1 : minOps;
    
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends