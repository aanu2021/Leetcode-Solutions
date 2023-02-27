//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> nums, int K) {
    
    int n = nums.size();
    
    int low = 0, high = n-1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == K) return mid;
        if(nums[mid] == nums[low] && nums[mid] == nums[high]){
            high--;
            continue;
        }
        if(nums[low] <= nums[mid]){
            if(K >= nums[low] && K <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(K >= nums[mid] && K <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    
    return -1;
    
}