class Solution {
public:
    
    vector<pair<int,int>>vec;
    
    int dp[605][105][105];
    
    int func(int i,int len,int m,int n,int cntm,int cntn){
        
        if(i>=len){
            return 0;
        }
        
        if(dp[i][cntm][cntn]!=-1){
            return dp[i][cntm][cntn];
        }
        
        int currval=func(i+1,len,m,n,cntm,cntn);
        
        int curr0=vec[i].first;
        int curr1=vec[i].second;
        
        if(cntm+curr0<=m && cntn+curr1<=n){
            currval=max(currval,1+func(i+1,len,m,n,cntm+curr0,cntn+curr1));
        }
        
        return dp[i][cntm][cntn]=currval;
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
      for(int i=0;i<strs.size();i++){
          
          int cnt0=0,cnt1=0;
          
          for(int j=0;j<strs[i].length();j++){
              if(strs[i][j]=='0'){
                  cnt0++;
              }else{
                  cnt1++;
              }
          }
          
          vec.push_back({cnt0,cnt1});
          
      }
        
      
        memset(dp,-1,sizeof(dp));
        
        int ans=func(0,strs.size(),m,n,0,0);
        
        return ans;
        
    }
};