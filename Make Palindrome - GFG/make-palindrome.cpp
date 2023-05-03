//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string,int>Map;
        for(int i=0;i<n;i++){
            Map[arr[i]]++;
        }
        int oddOcc = 0;
        for(auto &itr : Map){
            string str = itr.first;
            int occ = itr.second;
            string rev = str;
            reverse(rev.begin(),rev.end());
            if(str==rev){
                oddOcc += (occ%2 ? 1 : 0);
                Map[str] = 0;
            }
            else{
                if(Map[str] != Map[rev]) return false;
                Map[str] = 0;
                Map[rev] = 0;
            }
        }
        if(oddOcc <= 1) return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends