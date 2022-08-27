class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int maxsum=INT_MIN;
        
        for(int c1=0;c1<n;c1++){
            
            vector<int>sums(m,0);
            
            for(int c2=c1;c2<n;c2++){
                
                for(int r=0;r<m;r++){
                    
                    sums[r]+=grid[r][c2];
                    
                }
                
                
                set<int>S;
                
                S.insert(0);
                
                int currsum=0;
                
                
                for(int sum:sums){
                    
                    currsum+=sum;
                    
                    auto itr=S.lower_bound(currsum-k);
                    
                    if(itr!=S.end()){
                        
                        maxsum=max(maxsum,currsum-(*itr));
                        
                    }
                    
                    S.insert(currsum);
                    
                }
                
            }
            
        }
        
        return maxsum;
        
    }
};