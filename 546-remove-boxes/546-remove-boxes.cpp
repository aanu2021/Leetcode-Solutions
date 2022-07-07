class Solution {
public:
    
    int dp[102][102][102];
    
    vector<pair<int,int>>groups;
    
    int sqr_func(int n){
        
        return n*n;
        
    }
    
    int func(int i,int j,int extra){
        
        if(i>j){
            
            return 0;
            
        }
        
        if(dp[i][j][extra]!=-1){
            
            return dp[i][j][extra];
            
        }
        
        
        int ans=sqr_func(groups[i].second+extra)+func(i+1,j,0);
        
        for(int k=i+1;k<=j;k++){
            
            if(groups[i].first==groups[k].first){
                
                ans=max(ans,func(i+1,k-1,0) + func(k,j,extra+groups[i].second));
                
            }
            
        }
        
        return dp[i][j][extra] = ans;
        
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        int n=boxes.size();
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        int prev=boxes[0],cnt=0;
        
        for(int i=0;i<n;++i){
            
            if(boxes[i]==prev){
                
                cnt++;
                
            }
            
            else{
                
                groups.push_back({prev,cnt});
                
                prev=boxes[i];
                
                cnt=1;
                
            }
            
        }
        
        if(cnt>0){
            
            groups.push_back({prev,cnt});
            
        }
        
        n=groups.size();
        
        int ans=func(0,n-1,0);
        
        return ans;
        
    }
};