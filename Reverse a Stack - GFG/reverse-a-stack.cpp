//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void pushAtBottom(stack<int>&S, int ele){
        if(S.size() == 0){
            S.push(ele);
            return;
        }
        int ele2 = S.top();
        S.pop();
        pushAtBottom(S,ele);
        S.push(ele2);
    }

    void Reverse(stack<int> &S){
        if(S.size() == 0) return;
        int ele = S.top(); 
        S.pop();
        Reverse(S);
        pushAtBottom(S,ele);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends