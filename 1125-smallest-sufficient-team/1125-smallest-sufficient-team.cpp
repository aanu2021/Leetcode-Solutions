class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int M = req_skills.size();
        int N = people.size();
        
        int MASK = (1<<M);
        int dp[N+1][MASK];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<MASK;j++){
                dp[i][j] = 1e9;
            }
        }
        
        unordered_map<string,int>id;
        for(int i=0;i<M;i++){
            id[req_skills[i]] = i;
        }
        
        dp[0][0] = 0;
        vector<int>answer;
        vector<int>maskArr(N+1);
        
        for(int i=0;i<N;i++){
            int cmask = 0;
            for(string &str : people[i]){
                cmask |= (1<<id[str]);
            }
            maskArr[i+1] = cmask;
        }
        
        for(int i=1;i<=N;i++){
            int cmask = maskArr[i];
            for(int j=0;j<MASK;j++){
                int nj = (j|cmask);
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                dp[i][nj] = min(dp[i][nj], 1 + dp[i-1][j]);
            }
        }
        
        int mask = MASK - 1;
        
        for(int i=N; i>=1 && mask>0; i--){
            int cmask = maskArr[i];
            for(int j=0;j<MASK;j++){
                if((j|cmask) == mask){
                    if(dp[i][mask] == 1 + dp[i-1][j]){
                        answer.push_back(i-1);
                        mask = j;
                        break;
                    }
                }
            }
        }
        
        sort(answer.begin(),answer.end());
        return answer;
        
    }
};