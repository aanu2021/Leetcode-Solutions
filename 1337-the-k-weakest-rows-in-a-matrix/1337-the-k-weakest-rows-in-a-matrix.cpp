class Solution {
public:
    
    bool static comp(const pair<int,int>&x,const pair<int,int>&y){
        if(x.first == y.first){
            return x.second < y.second;
        }
        return x.first < y.first;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>vec;
        for(int i=0;i<m;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) cnt++;
            }
            vec.push_back({cnt,i});
        }
        sort(vec.begin(),vec.end(),comp);
        vector<int>answer;
        for(int i=0;i<k;i++){
            answer.push_back(vec[i].second);
        }
        return answer;
    }
};