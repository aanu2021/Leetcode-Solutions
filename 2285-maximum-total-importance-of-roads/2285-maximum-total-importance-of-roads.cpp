class Solution {
public:
    
    typedef long long ll;
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<ll>indegree(n,0LL);
        
        for(ll i=0;i<roads.size();i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
        }
        
        sort(indegree.rbegin(),indegree.rend());
        
        ll ans=0LL;
        
        ll k=n;
        
        for(ll i=0;i<n;i++){
            
            ans+=(k*indegree[i]);
            k--;
            
        }
        
        return ans;
        
    }
};