//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int>answer;
    void func(vector<int>&arr,int i,int sum,int N){
        if(i==N){
            answer.push_back(sum);
            return;
        }
        func(arr,i+1,sum,N);
        func(arr,i+1,sum+arr[i],N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        answer.clear();
        func(arr,0,0,N);
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends