//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static comp(const pair<int,int>&x,const pair<int,int>&y){
        return x.first < y.first;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {arr[i].dead,arr[i].profit};
        }
        sort(vec.begin(),vec.end(),comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        int total = 0, profit = 0;
        for(int i=0;i<n;i++){
            if(total + 1 <= vec[i].first){
                total++;
                profit += vec[i].second;
                pq.push(vec[i].second);
            }
            else if(!pq.empty() && pq.top() < vec[i].second){
                profit -= pq.top(); pq.pop();
                profit += vec[i].second;
                pq.push(vec[i].second);
            }
        }
        return {total, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends