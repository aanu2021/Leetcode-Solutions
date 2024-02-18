class Solution {
public:
    
    typedef long long ll;
    
    int mostBooked(int m, vector<vector<int>>& meetings) {
        int n = meetings.size();
        vector<ll>occurence(m, 0);
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>used;
        
        priority_queue<ll,vector<ll>,greater<ll>>available;
        
        for(int i=0;i<m;i++){
            available.push((ll)i);
        }
        
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++){
            ll starti = (ll)meetings[i][0];
            ll endi = (ll)meetings[i][1];
            ll duration = (ll)endi - (ll)starti;
            // free the already used rooms, whose ending is already been over
            while(!used.empty() && used.top().first <= starti){
                available.push(used.top().second);
                used.pop();
            }
            // Currently we have available rooms
            if(!available.empty()){
                ll avl_room = available.top(); available.pop();
                occurence[avl_room]++;
                used.push({(ll)endi, (ll)avl_room});
            }
            // Currently we have no available rooms
            else{
                auto curr = used.top(); used.pop();
                ll ending = curr.first;
                ll room = curr.second;
                occurence[room]++;
                used.push({ending + duration, room});
            }
        }
        
        return max_element(occurence.begin(),occurence.end()) - occurence.begin();

    }
};


/*

    m = 4
    
    2,13
    3,12
    7,10
    17,19
    18,19
    
    
    dp[0] = 1   dp[1] = 1   dp[2] = 1   dp[3] = 1
        
    13,0   12,1   10,2   19,3
        
    1. Priority queue to store the available rooms in ascending order
    2. Priority queue to store the currently used rooms' next availaibility


  */      
        