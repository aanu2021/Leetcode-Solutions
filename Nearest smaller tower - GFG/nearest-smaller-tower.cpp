//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        stack<int>S;
        
        vector<int>ns(n,n);
        vector<int>ps(n,-1);
        
        for(int i=0;i<n;i++){
            while(!S.empty() && arr[i] <= arr[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                ps[i] = S.top();
            }
            S.push(i);
        }
        
        while(!S.empty()) S.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && arr[i] <= arr[S.top()]){
                S.pop();
            }
            if(!S.empty()){
                ns[i] = S.top();
            }
            S.push(i);
        }
        
        vector<int>answer(n,-1);
        
        for(int i=0;i<n;i++){
            int left = ps[i];
            int right = ns[i];
            if(left==-1 && right==n) continue;
            if(left==-1){
                answer[i] = right;
            }
            else if(right==n){
                answer[i] = left;
            }
            else{
                int ldt = i-left;
                int rdt = right-i;
                if(ldt < rdt){
                    answer[i] = left;
                }
                else if(ldt > rdt){
                    answer[i] = right;
                }
                else{
                    if(arr[left] < arr[right]){
                        answer[i] = left;
                    }
                    else if(arr[left] > arr[right]){
                        answer[i] = right;
                    }
                    else{
                        answer[i] = left;
                    }
                }
            }
        }
        
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends