//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        if(l > h) return -1;
        int m = (l + h)/2;
        if(A[m] == key) return m;
        if(A[m] == A[l] && A[m] == A[h]){
            return search(A,l+1,h,key);
        }
        else if(A[l] <= A[m]){
            if(key >= A[l] && key <= A[m]){
                return search(A,l,m-1,key);
            }
            else{
                return search(A,m+1,h,key);
            }
        }
        else{
            if(key >= A[m] && key <= A[h]){
                return search(A,m+1,h,key);
            }
            else{
                return search(A,l,m-1,key);
            }
        }
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends