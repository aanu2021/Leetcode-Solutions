//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static comp(const pair<int,int>&x,const pair<int,int>&y){
        return x.second < y.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>intervals(n);
        for(int i=0;i<n;i++){
            intervals[i] = {start[i], end[i]};
        }
        sort(intervals.begin(),intervals.end(),comp);
        int ans = 1;
        pair<int,int>curr = intervals[0];
        for(int i=1;i<n;i++){
            if(intervals[i].first > curr.second){
                curr = intervals[i];
                ans++;
            }
        }
        return ans;
    }
};

 



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends