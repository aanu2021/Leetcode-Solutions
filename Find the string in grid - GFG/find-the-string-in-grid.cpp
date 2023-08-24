//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,1,-1};

    bool isSafe(vector<vector<char>>&grid,int x,int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    bool isPossible(vector<vector<char>>&grid,string &word,int i,int j){
        
        int x = i, y = j;
        int k = word.length();
        
        for(int dir=0;dir<8;dir++){
            int ni = dx[dir];
            int nj = dy[dir];
            int len = k;
            x = i, y = j;
            int idx = 0;
            bool flag = true;
            while(len > 0){
                if(isSafe(grid,x,y) == false){
                    flag = false;
                    break;
                }
                if(grid[x][y] != word[idx]){
                    flag = false;
                    break;
                }
                idx++;
                x += ni;
                y += nj;
                len--;
            }
            if(flag){
                return true;
            }
        }
        
        return false;
        
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
	    vector<vector<int>>answer;
	    
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j] == word[0]){
	                if(isPossible(grid,word,i,j)){
	                    answer.push_back({i,j});
	                }
	            }
	        }
	    }
	    
	    sort(answer.begin(),answer.end());
	    return answer;
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends