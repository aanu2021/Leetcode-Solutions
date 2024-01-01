class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        multiset<int>ms;
        for(int i=0;i<n;i++){
            ms.insert(s[i]);
        }
        sort(g.begin(),g.end());
        int answer = 0;
        for(int i=0;i<m;i++){
            if(ms.size() == 0) break;
            auto itr = ms.lower_bound(g[i]);
            if(itr == ms.end()) break;
            answer++;
            ms.erase(itr);
        }
        return answer;
    }
};