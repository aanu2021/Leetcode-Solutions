//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int shortestUnorderedSubarray(int arr[], int n)
    {
         if(n<3)

            return 0;

        else

        {

            for(int i=0;i<n-2;i++)

            {

                if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2])

                    return 3;

                else if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2])

                    return 3;

            }

            return 0;

        }
    }
};

// 7 9 10 8 11
// 7 8 9 10 11



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) 
            cin >> a[i];
        Solution obj;
        cout << obj.shortestUnorderedSubarray(a, n) << endl;
    }
}

// } Driver Code Ends