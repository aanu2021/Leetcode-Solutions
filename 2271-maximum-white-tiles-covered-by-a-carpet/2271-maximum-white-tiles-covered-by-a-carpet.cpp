class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int k) {
        
        int n=tiles.size();
        
        sort(tiles.begin(),tiles.end());
        
        int ans=0;
        
        vector<int>prefix(n,0);
        
        prefix[0]=(tiles[0][1]-tiles[0][0]+1);
        
        for(int i=1;i<n;i++){
            
            prefix[i]=prefix[i-1]+(tiles[i][1]-tiles[i][0]+1);
            
        }
        
        vector<int>v;
        
        for(int i=0;i<n;i++){
            v.push_back(tiles[i][0]);
        }
        
        for(int i=0;i<n;i++){
            
            auto itr=lower_bound(v.begin(),v.end(),tiles[i][0]+k);
            
            if(itr!=v.end() && (*itr)>tiles[i][0]+k){
                
                itr--;
                
            }
            
            int temp=(itr-v.begin()-1>=0 ? prefix[itr-v.begin()-1] : 0) - (i-1>=0 ? prefix[i-1] : 0);
            
            if(itr!=v.end() && (tiles[i][0]+k)>=(*itr)){
                
                temp+=min(tiles[i][0]+k-(*itr),prefix[itr-v.begin()]-(itr-v.begin()-1>=0 ? prefix[itr-v.begin()-1] : 0));
                
            }
            
            ans=max(ans,temp);
            
        }
        
        return ans;
        
    }
};