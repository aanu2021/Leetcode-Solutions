class Solution {
public:
    
    typedef long long ll;
    
    struct comp{
      
        bool operator()(const pair<int,int>&x,const pair<int,int>&y){
            if(x.first == y.first) return x.second > y.second;
            return x.first > y.first;
        }
        
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        ll currtime = 0LL;
        int idx = 0;
        
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        while(idx<n || !pq.empty()){
            
            while(idx<n && (ll)tasks[idx][0] <= currtime){
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }
            
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                currtime += (ll)pq.top().first;
                pq.pop();
            }
            else{
                currtime = (ll)tasks[idx][0];
            }
            
        }
        
        return ans;
        
    }
};