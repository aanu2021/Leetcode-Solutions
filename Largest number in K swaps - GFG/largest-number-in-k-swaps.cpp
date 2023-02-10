//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void findMaximumNum(
    string str, int k,
    string& max, int ctr)
{
    // return if no swaps left
    if (k == 0)
        return;
 
    int n = str.length();
 
    // Consider every digit after
    // the cur position
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {
        // Find maximum digit greater
        // than at ctr among rest
        if (maxm < str[j])
            maxm = str[j];
    }
 
    // If maxm is not equal to str[ctr],
    // decrement k
    if (maxm != str[ctr])
        --k;
 
    // search this maximum among the rest from behind
    //first swap the last maximum digit if it occurs more than 1 time
   //example str= 1293498 and k=1 then max string is 9293418 instead of 9213498
    for (int j = n-1; j >=ctr; j--) {
        // If digit equals maxm swap
        // the digit with current
        // digit and recurse for the rest
        if (str[j] == maxm) {
            // swap str[ctr] with str[j]
            swap(str[ctr], str[j]);
 
            // If current num is more than
            // maximum so far
            if (str.compare(max) > 0)
                max = str;
 
            // recurse other swaps after cur
            findMaximumNum(str, k, max, ctr + 1);
 
            // Backtrack
            swap(str[ctr], str[j]);
        }
    }
}
    string findMaximumNum(string str, int k)
    {
       int n = str.length();
       string max = str;
       findMaximumNum(str,k,max,0);
       return max;
    }
};


/*

4 5 5 1 7 1 1 5 2 7
0 1 2 3 4 5 6 7 8 9

1 -> 3 5 6
2 -> 8
4 -> 9
5 -> 1 2 7
7 -> 4 

*/


// 5 5 3 4 3 3 3
// 0 1 2 3 4 5 6

// k = 1

// 3 -> 2 4 5 6
// 4 -> 
// 5 ->  





//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends