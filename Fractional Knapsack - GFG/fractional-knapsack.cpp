// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0.0;
        
        vector<pair<double,int>>vec(n);
        
        for(int i=0;i<n;i++){
            
            double curr=(arr[i].value*1.0)/(arr[i].weight);
            
            vec[i]={curr,arr[i].weight};
            
        }
        
        sort(vec.rbegin(),vec.rend());
        
        for(int i=0;i<n;i++){
            
            double ratio=vec[i].first;
            int currwt=vec[i].second;
            
            if(W>=currwt){
                W-=currwt;
                ans+=(ratio*currwt);
            }
            else{
                ans+=(ratio*W);
                break;
            }
            
        }
        
        return ans;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends