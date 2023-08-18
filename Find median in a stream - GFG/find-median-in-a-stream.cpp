//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0){
            maxHeap.push(x);
            return;
        }
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(x);
        }
        else{
            minHeap.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxHeap.top() > minHeap.top()){
            int e1 = maxHeap.top(); maxHeap.pop();
            int e2 = minHeap.top(); minHeap.pop();
            maxHeap.push(e2);
            minHeap.push(e1);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int sz1 = maxHeap.size();
        int sz2 = minHeap.size();
        int sz = sz1+sz2;
        if(sz%2){
            return 1.0*maxHeap.top();
        }
        else{
            return (maxHeap.top() + minHeap.top())/2.0;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends