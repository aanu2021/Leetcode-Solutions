class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>team;
        int n = scores.size();
        for(int i=0;i<n;i++){
            team.push_back({ages[i],scores[i]});
        }
        sort(team.begin(),team.end());
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = team[i].second;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(team[i].second >= team[j].second){
                    dp[i] = max(dp[i],dp[j] + team[i].second);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
