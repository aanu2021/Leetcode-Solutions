//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
       
       unordered_map<int,int>m;
       
       int total_time = 0;
       
       for(int i=0;i<n;i++){
           if(m.find(arr[i])==m.end()){
               m[arr[i]] = total_time; 
           }
           else{
               total_time = max(total_time,m[arr[i]] + time[arr[i]-1]);
               m[arr[i]] = total_time;
           }
           total_time++;
       }
       return total_time-1;
       
    }
};

/*

1 2 3 3 3
1 2 3 4 5

total = 1 + 1 + 1 + 1 + 2 + 2

wait[1] = 0
wait[2] = 1
wait[3] = 2

*/



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        
        vector<int> time(n);
        Array::input(time,n);
        
        Solution obj;
        int res = obj.totalTime(n, arr, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends