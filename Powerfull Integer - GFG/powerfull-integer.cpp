//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        set<int>S;
        for(int i=0;i<n;i++){
            S.insert(intervals[i][0]);
            S.insert(intervals[i][1]);
        }
        vector<int>v;
        for(auto &ele : S){
            v.push_back(ele);
        }
        int m = v.size();
        unordered_map<int,int>ID;
        unordered_map<int,int>revMap;
        int id = 0;
        for(int i=0;i<m;i++){
            revMap[id] = v[i];
            ID[v[i]] = id++;
        }
        vector<int>freq(m+5,0);
        for(int i=0;i<n;i++){
            freq[ID[intervals[i][0]]]++;
            freq[ID[intervals[i][1]] + 1]--;
        }
        for(int i=1;i<=m+2;i++){
            freq[i] += freq[i-1];
        }
        int maxVal = -1;
        for(int i=0;i<=m;i++){
            if(freq[i] >= k){
                maxVal = max(maxVal,revMap[i]);
            }
        }
        return maxVal;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends