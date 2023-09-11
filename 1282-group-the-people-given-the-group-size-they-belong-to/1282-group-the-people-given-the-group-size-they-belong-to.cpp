class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n = g.size();
        vector<vector<int>>group(n+1);
        for(int i=0;i<g.size();i++){
            group[g[i]].push_back(i);
        }
        vector<vector<int>>answer;
        for(int i=1;i<=n;i++){
            if(group[i].size() == 0) continue;
            int req = i;
            int have = group[i].size();
            int sep_group = have/req;
            for(int j=0;j<have;j+=req){
                vector<int>temp;
                for(int k=j;k<=j+req-1;k++){
                    temp.push_back(group[i][k]);
                }
                answer.push_back(temp);
            }
        }
        return answer;
    }
};

    