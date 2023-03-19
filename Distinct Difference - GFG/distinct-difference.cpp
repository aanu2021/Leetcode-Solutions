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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        vector<int>Left(N,0);
        vector<int>Right(N,0);
        unordered_set<int>S;
        for(int i=0;i<N;i++){
            Left[i] = S.size();
            S.insert(A[i]);
        }
        S.clear();
        for(int i=N-1;i>=0;i--){
            Right[i] = S.size();
            S.insert(A[i]);
        }
        vector<int>answer(N,0);
        for(int i=0;i<N;i++){
            answer[i] = Left[i] - Right[i];
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends