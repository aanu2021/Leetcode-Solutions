//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    bool static comp(const pair<int,int>&x, const pair<int,int>&y){
        return x.second < y.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {start[i],end[i]};
        }
        sort(vec.begin(),vec.end(),comp);
        int total = 1;
        int endTime = vec[0].second;
        for(int i=1;i<n;i++){
            if(vec[i].first > endTime){
                total++;
                endTime = vec[i].second;
            }
        }
        return total;
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