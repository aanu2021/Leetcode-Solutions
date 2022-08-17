class Solution {
public:
    int kthSmallest(vector<vector<int>>& grid, int k) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int>temp=grid[0];
        
        for(int i=1;i<m;++i){
            
            vector<int>curr;
            
            for(int j=0;j<n;++j){
                
                for(int itr=0;itr<temp.size();itr++){
                    
                    curr.push_back(temp[itr]+grid[i][j]);
                    
                }
                
            }
            
            sort(curr.begin(),curr.end());
            
            int sz=curr.size(); 
            
            temp.clear();
            
            for(int j=0;j<min(sz,k);++j){
                
                temp.push_back(curr[j]);
                
            }
            
        }
        
        return temp[k-1];
        
    }
};