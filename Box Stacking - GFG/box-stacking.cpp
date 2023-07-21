//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        return x[0] + x[1] > y[0] + y[1]; 
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            vector<int>arr(3);
            arr[0] = min(width[i],length[i]);
            arr[1] = max(width[i],length[i]);
            arr[2] = height[i];
            vec.push_back(arr);
            arr[0] = min(width[i],height[i]);
            arr[1] = max(width[i],height[i]);
            arr[2] = length[i];
            vec.push_back(arr);
            arr[0] = min(height[i],length[i]);
            arr[1] = max(height[i],length[i]);
            arr[2] = width[i];
            vec.push_back(arr);
        }
        
        n = 3*n;
        
        sort(vec.begin(),vec.end(),comp);
        
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i] = vec[i][2];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1]){
                    dp[i] = max(dp[i], dp[j] + vec[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends