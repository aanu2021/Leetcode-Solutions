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
        int r = l + n - 1;
        int k = 0;
        int ops = 0;
        string temp = s1;
        for(int i=l;i<=r;i++){
            if(s1[i] != s2[k]) ops++;
            s1[i] = s2[k++];
        }
        // cout<<ops<<"\n";
        for(int i=0;i<m;i++){
            int j = m-i-1;
            // if(l==2)
            // cout<<i<<" "<<j<<"\n";
            if(i >= l && i <= r){
                if(j >= l && j <= r){
                    if(s1[i] != s1[j]) return 1e9;
                }
                else{
                    s1[j] = s1[i];
                    ops++;
                }
            }
            else{
                if(s1[i] != s1[j]){
                    s1[i] = s1[j];
                    ops++;
                }
            }
        }
        ops = 0;
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
            // cout<<currOps<<"\n";
            minOps = min(minOps,currOps);
        }
        
        if(minOps >= 1e9) return -1;
        else return minOps;
        
    }
};

/*

u i j q y s u y
        i u s t
0 1 2 3 4 5 6 7

4 + 2

*/

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