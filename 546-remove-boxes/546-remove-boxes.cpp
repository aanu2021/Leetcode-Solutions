class Solution {
public:
    
    int dp[102][102][102];
    
    vector<pair<int,int>>groups;
    
    int func(int i,int j,int extra){
        
        if(i>j){
            return 0;
        }
        

        if(dp[i][j][extra]!=-1){
            return dp[i][j][extra];
        }
        
        int currscore=(groups[i].second+extra)*(groups[i].second+extra) + func(i+1,j,0);
        
        for(int k=i+1;k<=j;++k){
            
            if(groups[i].first==groups[k].first){
                
                currscore=max(currscore,func(i+1,k-1,0)+func(k,j,groups[i].second+extra));
                
            }
            
        }
        
        return dp[i][j][extra] = currscore;
        
    }
    
    int removeBoxes(vector<int>& boxes) {
        
        int n=boxes.size();
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;++i){
            
            int j=i;
            
            int cnt=0;
            
            
            while(j<n && boxes[j]==boxes[i]){
                
                j++;
                cnt++;
                
            }
            
            groups.push_back({boxes[i],cnt});
            
            i=j;
            i--;
            
        }
        
        n=groups.size();
        
        int ans=func(0,n-1,0);
        
        return ans;
        
    }
};