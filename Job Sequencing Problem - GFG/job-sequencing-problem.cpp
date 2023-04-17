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
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({arr[i].dead,arr[i].profit});
        }
        sort(jobs.begin(),jobs.end());
        int timer = 0;
        int profit = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(timer < jobs[i][0]){
                timer++;
                pq.push(jobs[i][1]);
                profit += jobs[i][1];
            }else{
                if(!pq.empty() && pq.top() < jobs[i][1]){
                    profit -= pq.top(); pq.pop();
                    pq.push(jobs[i][1]); profit += jobs[i][1];
                }
            }
        }
        return {timer,profit};
    } 
};


// 1 10
// 1 30
// 1 40
// 4 20

// timer  =  2
// profit =  60



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