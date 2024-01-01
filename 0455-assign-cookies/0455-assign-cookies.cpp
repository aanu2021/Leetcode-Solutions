class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int ans = 0, i = 0, j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<m && j<n){
            while(j<n && g[i] > s[j]) j++;
            if(j == n) break;
            ans++;
            i++; j++;
        }
        return ans;
    }
};