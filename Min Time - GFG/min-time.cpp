//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    typedef long long ll;
  
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        
        map<int,int>minLocation;
        map<int,int>maxLocation;
        
        for(int i=0;i<n;i++){
            
            if(minLocation.find(types[i]) == minLocation.end()){
                minLocation[types[i]] = locations[i];
            }
            else{
                minLocation[types[i]] = min(minLocation[types[i]],locations[i]);
            }
            
            if(maxLocation.find(types[i]) == maxLocation.end()){
                maxLocation[types[i]] = locations[i];
            }
            else{
                maxLocation[types[i]] = max(maxLocation[types[i]],locations[i]);
            }
            
        }
        
        vector<int>LEFT;
        vector<int>RIGHT;
        
        for(auto &itr : minLocation){
            LEFT.push_back(itr.second);
        }
        for(auto &itr : maxLocation){
            RIGHT.push_back(itr.second);
        }
        
        n = LEFT.size();
        
        vector<vector<ll>>dp(n,vector<ll>(2,1e16));
        
        dp[0][1] = abs(LEFT[0]) + abs(LEFT[0]-RIGHT[0]);
        dp[0][0] = abs(RIGHT[0]) + abs(RIGHT[0] - LEFT[0]);
        
        for(int i=1;i<n;i++){
            
            dp[i][0] = abs(LEFT[i-1]-RIGHT[i]) + dp[i-1][0] + abs(RIGHT[i]-LEFT[i]);
            dp[i][0] = min(dp[i][0],abs(RIGHT[i-1]-RIGHT[i]) + dp[i-1][1] + abs(RIGHT[i]-LEFT[i]));
            
            dp[i][1] = abs(LEFT[i-1]-LEFT[i]) + dp[i-1][0] + abs(LEFT[i]-RIGHT[i]);
            dp[i][1] = min(dp[i][1],abs(RIGHT[i-1]-LEFT[i]) + dp[i-1][1] + abs(LEFT[i]-RIGHT[i]));
            
        }
        
        return min(dp[n-1][0] + (ll)abs(LEFT[n-1]),dp[n-1][1] + (ll)abs(RIGHT[n-1]));
        
    }
};

// types -> 1  2  3

// left  -> 1  3  5

// right -> 7  3  5

// dp[0] -> 13 

// dp[1] -> 7



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends