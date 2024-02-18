class Solution {
public:
    
    typedef long long ll;
    
    int mostBooked(int m, vector<vector<int>>& meetings) {
        int n = meetings.size();
        vector<ll>occurence(m,0LL);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>used;
        priority_queue<ll,vector<ll>,greater<ll>>available;
        
        for(int i=0;i<m;i++){
            available.push((ll)i);
        }
        
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++){
            ll L = (ll)meetings[i][0];
            ll R = (ll)meetings[i][1];
            ll duration = (ll)R - (ll)L;
            while(!used.empty() && used.top().first <= L){
                available.push(used.top().second);
                used.pop();
            }
            if(!available.empty()){
                ll room = available.top(); available.pop();
                occurence[room]++;
                used.push({R, room});
            }
            else{
                auto curr = used.top(); used.pop();
                ll timer = curr.first;
                ll room = curr.second;
                occurence[room]++;
                used.push({timer + duration, room});
            }
        }
        return max_element(occurence.begin(),occurence.end()) - occurence.begin();
    }
};