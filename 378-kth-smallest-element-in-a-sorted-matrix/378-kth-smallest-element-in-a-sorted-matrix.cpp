class Solution {
public:
    
    bool isPossible(vector<vector<int>>&grid,int ele,int k){
        
        int cnt=0;
        
        for(int i=0;i<grid.size();i++){
            
            int idx=upper_bound(grid[i].begin(),grid[i].end(),ele)-grid[i].begin();
            
            cnt+=idx;
            
        }
        
        return cnt>=k;
        
    }
    
    int kthSmallest(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        
        int low=grid[0][0];
        int high=grid[n-1][n-1];
        
        int ans=-1;
        
        while(low<=high){
            
            int mid=(low+high)/2;
            
            if(isPossible(grid,mid,k)==true){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        
        return ans;
        
    }
};