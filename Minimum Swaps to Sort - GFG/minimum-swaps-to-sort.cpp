// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    
	    map<int,int>mp;
	    
	    vector<int>arr;
	    
	    for(int i=0;i<n;i++){
	        mp[nums[i]]=i;
	    }
	    
	    arr=nums;
	    
	    sort(arr.begin(),arr.end());
	    
	    vector<bool>visited(n,false);
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++){
	        
	        if(visited[i]==true || arr[i]==nums[i]){
	            visited[i]=true;
	            continue;
	        }
	        
	        int j=i;
	        
	        int cycle=0;
	        
	        while(visited[j]==false){
	            
	            visited[j]=true;
	            
	            j=mp[arr[j]];
	            
	            cycle++;
	            
	        }
	        
	        ans+=(cycle-1);
	        
	    }
	    
	    return ans;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends