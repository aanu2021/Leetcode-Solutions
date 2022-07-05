class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n=startTime.size();
        
        vector<vector<int>>vec(n,vector<int>(3));
        
        for(int i=0;i<n;++i){
            
            vec[i][0]=startTime[i];
            vec[i][1]=endTime[i];
            vec[i][2]=profit[i];
            
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        vector<int>dp(n,0);
        
        dp[0]=vec[0][2];
        
        for(int i=1;i<n;++i){
            
            int inc=-1;
            
            int currprofit=vec[i][2];
            
            int low=0,high=i-1;
            
            while(low<=high){
                
                int mid=(low+high)/2;
                
                if(vec[mid][1]<=vec[i][0]){
                    
                    inc=mid;
                    low=mid+1;
                    
                }
                
                else{
                    
                    high=mid-1;
                    
                }
                
            }
            
            if(inc!=-1){
                
                currprofit+=dp[inc];
                
            }
            
            dp[i]=max(dp[i-1],currprofit);
            
        }
        
        return dp[n-1];
        
    }
};