class Solution {
public:
    
    typedef long long ll;
    
    int mostBooked(int n, vector<vector<int>>& meets) {
        
        vector<ll>cnt(n,0LL);
        
        sort(meets.begin(),meets.end());
        
        priority_queue<ll,vector<ll>,greater<ll>>avail;
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>busy;
        
        for(ll i=0;i<n;++i){
            
            avail.push(i);
            
        }
        
        
        for(auto &m:meets){
            
            while(!busy.empty() && busy.top().first<=m[0]){
                
                avail.push(busy.top().second);
                
                busy.pop();
                
            }
            
            ll start=(avail.empty() ? busy.top().first : m[0]);
            
            ll duration=(ll)(m[1]-m[0]);
            
            ll room=(avail.empty() ? busy.top().second : avail.top());
            
            busy.push({start+duration,room});
            
            cnt[room]++;
            
            if(avail.empty()){
                busy.pop();
            }else{
                avail.pop();
            }
            
        }
        
        return max_element(cnt.begin(),cnt.end())-cnt.begin();
        
    }
};