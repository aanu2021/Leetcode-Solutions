class Solution {
public:
    
    int dp[105][105][105];
    
    vector<pair<int,int>>groups;
    
    int sqr(int n){
        return (n*n);
    }
    
    int func(int i,int j,int extra){
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j][extra]!=-1){
            return dp[i][j][extra];
        }
        
        int curr_grp_sz=groups[i].second+extra;
        
        int ans=sqr(curr_grp_sz)+func(i+1,j,0);
        
        for(int group=i+1;group<=j;group++){
            
            if(groups[i].first==groups[group].first){
                
                ans=max(ans,func(i+1,group-1,0)+func(group,j,extra+groups[i].second));
                
            }
            
        }
        
        return dp[i][j][extra] = ans;
        
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        int n=boxes.size();
        
        for(int i=0;i<=n+1;++i){
            for(int j=0;j<=n+1;++j){
                for(int k=0;k<=n+1;++k){
                    dp[i][j][k]=-1;
                }
            }
        }
        
        int cnt=0;
        
        int prev=boxes[0];
        
        for(int i=0;i<n;++i){
            
            if(boxes[i]==prev){
                cnt++;
            }
            
            else{
                groups.push_back({prev,cnt});
                cnt=1;
                prev=boxes[i];
            }
            
        }
        
        if(cnt!=0){
            groups.push_back({prev,cnt});
        }
        
        n=groups.size();
        
        // for(int i=0;i<n;++i){
        //     cout<<groups[i].first<<" "<<groups[i].second<<endl;
        // }cout<<"\n";
        
        int ans=func(0,n-1,0);
        
        return ans;
        
    }
};