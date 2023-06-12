//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int>>pq;
	    for(int i=0;i<n;i++){
	        if(pq.size() < k){
	            pq.push(arr[i]);
	        }
	        else if(!pq.empty() && pq.top() < arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    vector<int>answer;
	    while(!pq.empty()){
	        answer.push_back(pq.top());
	        pq.pop();
	    }
	    reverse(answer.begin(),answer.end());
	    return answer;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends