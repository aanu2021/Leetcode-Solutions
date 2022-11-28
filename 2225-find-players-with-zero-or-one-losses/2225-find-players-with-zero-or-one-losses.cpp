class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mapp;
        for(int i=0;i<matches.size();i++){
            mapp[matches[i][1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto &itr:mapp){
            if(itr.second==1){
                ans[1].push_back(itr.first);
            }
        }
        unordered_map<int,int>winner;
        for(int i=0;i<matches.size();i++){
            winner[matches[i][0]]++;
        }
        for(auto &itr:winner){
            if(mapp[itr.first]==0){
                ans[0].push_back(itr.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};