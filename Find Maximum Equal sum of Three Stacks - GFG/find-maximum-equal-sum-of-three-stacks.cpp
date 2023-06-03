//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int maxSum = 0;
        
        int currSum1 = 0, currSum2 = 0,currSum3 = 0;
        
        int j = N2-1,k = N3-1;
        
        for(int i=N1-1;i>=0;i--){
            currSum1 += S1[i];
            while(j >= 0 && currSum2 < currSum1){
                currSum2 += S2[j];
                j--;
            }
            while(k >= 0 && currSum3 < currSum1){
                currSum3 += S3[k];
                k--;
            }
            if(currSum1 == currSum2 && currSum2 == currSum3){
                maxSum = max(maxSum,currSum1);
            }
        }
        
        return maxSum;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends