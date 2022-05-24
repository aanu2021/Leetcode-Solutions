// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    
	    int n=nums.size();
	    
	    vector<int>inc(n,1);
	    vector<int>dec(n,1);
	    
	    for(int i=1;i<n;i++){
	        
	        for(int j=0;j<i;j++){
	            
	            if(nums[j]<nums[i]){
	                
	                inc[i]=max(inc[i],inc[j]+1);
	                
	            }
	            
	        }
	        
	    }
	    
	    
	    for(int i=n-2;i>=0;i--){
	        
	        for(int j=i+1;j<n;j++){
	            
	            if(nums[j]<nums[i]){
	                
	                dec[i]=max(dec[i],dec[j]+1);
	                
	            }
	            
	        }
	        
	    }
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++){
	        ans=max(ans,inc[i]+dec[i]-1);
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
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends