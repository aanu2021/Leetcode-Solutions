class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>answer;
        while(!q.empty()){
            auto [row,col] = q.front(); q.pop();
            answer.push_back(grid[row][col]);
            if(col==0 && row + 1 < grid.size()){
                q.push({row+1, col});
            }
            if(col + 1 < grid[row].size()){
                q.push({row, col+1});
            }
        }
        return answer;
    }
};