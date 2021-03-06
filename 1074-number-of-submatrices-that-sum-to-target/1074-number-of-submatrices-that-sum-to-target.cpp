class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            
            for(int j=1;j<n;j++){
                
                grid[i][j]+=grid[i][j-1];
                
            }
            
        }
        
        int ans=0;
        
        for(int c1=0;c1<n;c1++){
            
            for(int c2=c1;c2<n;c2++){
                
                map<int,int>mp;
                
                mp[0]=1;
                
                int sum=0;
                
                for(int row=0;row<m;row++){
                    
                    sum+=grid[row][c2]-(c1-1>=0 ? grid[row][c1-1] : 0);
                    
                    if(mp.find(sum-target)!=mp.end()){
                        
                        ans+=mp[sum-target];
                        
                    }
                    
                    mp[sum]++;
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};