class Solution {
public:
    
    vector<int> top_sort(int k, vector<vector<int>>& conditions) {
    vector<int> sorted, id(k), pre(k + 1), q;
    vector<unordered_set<int>> al(k + 1);
    for (auto &c : conditions)
        if(al[c[0]].insert(c[1]).second)
            ++pre[c[1]];
    for (auto i = 1; i <= k; ++i)
        if (pre[i] == 0)
            q.push_back(i);
    while (!q.empty()) {
        vector<int> q1;
        for (auto i : q) {
            sorted.push_back(i);
            for (auto j : al[i])
                if (--pre[j] == 0)
                    q1.push_back(j);
        }
        swap(q, q1);
    }
    if (sorted.size() != k)
        return {};
        
        for(int i:sorted){
            cout<<i<<" ";
        }cout<<"\n";
        
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](int a, int b){ return sorted[a] < sorted[b]; });
        
    for(int i:id){
        cout<<i<<" ";
    }cout<<"\n";
        
    return id;
}
vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    auto rid = top_sort(k, rowConditions), cid = top_sort(k, colConditions);
    if (rid.empty() || cid.empty())
        return {};
    vector<vector<int>> res(k, vector<int>(k));    
    for (int i = 1; i <= k; ++i)
        res[rid[i - 1]][cid[i - 1]] = i;
    return res;
}
    
};