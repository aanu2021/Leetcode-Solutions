//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    typedef long long ll;
    vector<long long> printFibb(int n) 
    {
        if(n==1) return {1};
        if(n==2) return {1,1};
        if(n==3) return {1,1,2};
        vector<ll>answer(n);
        answer[0] = 1LL;
        answer[1] = 1LL;
        answer[2] = 2LL;
        for(int i=3;i<n;i++){
            answer[i] = answer[i-1] + answer[i-2];
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends