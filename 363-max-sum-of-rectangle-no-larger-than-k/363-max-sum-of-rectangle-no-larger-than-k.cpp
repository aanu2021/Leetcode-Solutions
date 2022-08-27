class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        int maxval=INT_MIN;
        
        for(int c1=0;c1<n;c1++){
            
            vector<int>sums(m,0);
            
            for(int c2=c1;c2<n;c2++){
                
                for(int i=0;i<m;++i){
                    
                    sums[i]+=grid[i][c2];
                    
                }
                
                set<int>S;
                
                S.insert(0);
                
                int currsum=0;
                
                for(int sum:sums){
                    
                    currsum+=sum;
                    
                    int target=(currsum-k);
                    
                    auto itr=S.lower_bound(target);
                    
                    if(itr!=S.end()){
                        
                        maxval=max(maxval,currsum-(*itr));
                        
                    }
                    
                    S.insert(currsum);
                    
                }
                
            }
            
        }
        
        return maxval;
        
    }
};