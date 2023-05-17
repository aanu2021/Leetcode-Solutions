//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        
        unordered_map<char,int>mp;
        mp['L'] = 0;
        mp['R'] = 1;
        mp['D'] = 2;
        mp['U'] = 3;
        
        int maxx=0,maxy=0,minx=0,miny=0;
        int x = 0,y = 0;
        
        for(char ch:s){
            
            x += dx[mp[ch]];
            y += dy[mp[ch]];
            
            maxx = max(maxx,x);
            maxy = max(maxy,y);
            
            minx = min(minx,x);
            miny = min(miny,y);
            
        }
        
        // cout<<minx<<" "<<maxx<<"\n";
        // cout<<miny<<" "<<maxy<<"\n";
        
        if((maxx-minx) >= n || (maxy-miny) >= m) return false;
        else return true;
        
    }
};


/*

L R U R D U

n = 9 
m = 2

*/


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends