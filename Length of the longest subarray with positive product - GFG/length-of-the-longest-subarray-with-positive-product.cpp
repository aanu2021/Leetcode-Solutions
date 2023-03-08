//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            int maxLen = 0;
            for(int i=0;i<n;i++){
                if(arr[i]==0) continue;
                int startIndex = i;
                int endIndex = i;
                int negCount = 0;
                int firstIdx = -1;
                int lastIdx = -1;
                while(endIndex < n && arr[endIndex] != 0){
                    if(arr[endIndex] < 0){
                        negCount++;
                        if(firstIdx == -1){
                            firstIdx = endIndex;
                        }
                        lastIdx = endIndex;
                    }
                    endIndex++;
                }
                if(negCount%2 == 0){
                    maxLen = max(maxLen,endIndex-startIndex);
                }
                else{
                    maxLen = max(maxLen,lastIdx-startIndex);
                    maxLen = max(maxLen,endIndex-1-firstIdx);
                }
                i = endIndex;
                i--;
            }
            return maxLen;
        }
};

/*

1. break them into chunks of non-zero numbers. [  ] 000 [  ] 0 [    ] 000 [ ]
2. now explore each and every potential chunk to get longest subarray 
3. now there may arise some cases :
   3.1. If all the elements are positive then we can take whole chunk in count
   3.2. If even number of negative numbers are present in the chunk , take whole chunk in count.
   3.3. only take care of first negative and last negative indices.
        [p,p,n,p,p,p,n,p,n,p,p,p]
        [start,lastNegative-1]
        [firstNegative+1,end]
        
*/        


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends