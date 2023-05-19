//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    vector<vector<int>>Merge_Interval(vector<vector<int>>&intervals,int n){
        
        vector<vector<int>>merged_interval;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int>interval = intervals[0];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0] <= interval[1]){
                interval[1] = max(interval[1],intervals[i][1]);
                continue;
            }
            else{
                merged_interval.push_back(interval);
                interval = intervals[i];
            }
        }
        
        merged_interval.push_back(interval);
        return merged_interval;
        
    }
    
    vector<int>kthSmallestNum(int n, vector<vector<int>>&intervals, int q, vector<int>queries){
        
        intervals = Merge_Interval(intervals,n);
        
        n = intervals.size();
        
        vector<int>answer(q);
        
        for(int i=0;i<q;i++){
            
            int k = queries[i];
            int value = -1;
            
            for(int j=0;j<n;j++){
                
                int total = intervals[j][1] - intervals[j][0] + 1;
                
                if(total < k){
                    k -= total;
                    continue;
                }
                else{
                    value = intervals[j][0] + k - 1;
                    break;
                }
                
            }
            
            answer[i] = value;
            
        }
        
        return answer;
        
    } 
};

/*

First use 'Merge Interval' technique to merge those intervals which are having some common elements inside them.

Then traverse them from left to right, and check number of elements that we can take at max to satisfy the query.

For merging it will take O(N*logN) 

And for traversing all the intervals in each possible query takes O(Q*N)

Overall time complexity : O(N*logN + Q*N)

*/


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends