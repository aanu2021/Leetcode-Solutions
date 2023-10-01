class Solution {
public:
    
    vector<pair<int,int>>groups;
    
    int dp[102][102][102];
    
    int func(int i,int j,int extra){
        if(i > j) return 0;
        if(dp[i][j][extra] != -1) return dp[i][j][extra];
        int maxScore = ((groups[i].second + extra)*(groups[i].second + extra)) + func(i+1,j,0);
        for(int k=i+1;k<=j;k++){
            if(groups[i].first == groups[k].first){
                maxScore = max(maxScore, func(i+1,k-1,0) + func(k,j,groups[i].second + extra));
            }
        }
        return dp[i][j][extra] = maxScore;
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        
        groups.clear();
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            int j = i, cnt = 0;
            while(j<n && boxes[i]==boxes[j]){
                cnt++;
                j++;
            }
            groups.push_back({boxes[i],cnt});
            i = j;
            i--;
        }
        n = groups.size();
        int ans = func(0,n-1,0);
        return ans;
    }
};