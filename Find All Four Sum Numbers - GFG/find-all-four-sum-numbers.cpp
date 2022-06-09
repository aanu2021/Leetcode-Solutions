// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        
        vector<vector<int>>ans;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            
            if(i==0 || nums[i]!=nums[i-1]){
                
                for(int j=i+1;j<n;j++){
                    
                    if(j==i+1 || nums[j]!=nums[j-1]){
                        
                        int low=j+1;
                        int high=n-1;
                        
                        while(low<high){
                            
                            int currsum=nums[i]+nums[j]+nums[low]+nums[high];
                            
                            if(currsum==target){
                                
                                ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                                
                                if(nums[low]==nums[high]){
                                    break;
                                }
                                
                                while(low+1<high && nums[low+1]==nums[low]){
                                    low++;
                                }
                                
                                while(low+1<high && nums[high-1]==nums[high]){
                                    high--;
                                }
                                
                                low++;
                                high--;
                                
                            }
                            
                            else if(currsum>target){
                                high--;
                            }
                            
                            else{
                                low++;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            
            
        }
        
          return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends