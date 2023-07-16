class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int M = req_skills.size();
        int MASK = (1<<M);
        int N = people.size();
        
        int dp[N+1][MASK];
        for(int i=0;i<=N;i++){
            for(int j=0;j<MASK;j++){
                dp[i][j] = 1e9;
            }
        }
        
        dp[0][0] = 0;
        
        unordered_map<string,int>id;
        
        for(int i=0;i<M;i++){
            id[req_skills[i]] = i;
        }
        
        vector<int>maskArr(N+1);
        
        for(int i=0;i<N;i++){
            int mask = 0;
            for(string &str : people[i]){
                mask |= (1<<id[str]);
            }
            // cout<<mask<<"\n";
            maskArr[i+1] = mask;
        }
        
        for(int i=1;i<=N;i++){
            int mask = maskArr[i];
            for(int j=0;j<MASK;j++){
                int nj = (j|mask);
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                dp[i][nj] = min(dp[i][nj], 1 + dp[i-1][j]);
            }
        }
        
        int mask = MASK - 1;
        vector<int>answer;
        
        // cout<<dp[N][MASK-1]<<"\n";
        
        for(int i=N;i>=1 && mask>0 ;i--){
             // cout<<mask<<" "<<maskArr[i]<<"\n";
             int cMask = maskArr[i];
             for(int j=0;j<MASK;j++){
                 if((j | cMask) == mask){
                     if(dp[i][mask] == 1 + dp[i-1][j]){
                         answer.push_back(i-1);
                         mask = j;
                         break;
                     }
                 }
             }
        }
        
        // for(int i=1;i<=N;i++){
        //     for(int j=0;j<MASK;++j){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
        sort(answer.begin(),answer.end());
        return answer;
        
    }
};

   /*
 
   java    -> 0
   nodeJs  -> 1
   reactJs -> 2
       
   dp[N+1][MASK]   MASK = (1<<M)
       
   dp[4][8]
   
   dp[0][0] = 0
       
   dp[]    
   
   0 1 2 3 4 5
   
   63
   
   1 + 2 + 4 = 7
   1 + 2 + 8 = 11
   4 + 16 + 32 = 52
   
   
   */