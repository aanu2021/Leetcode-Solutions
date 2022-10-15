    /*

    sum(speed) * minimum(efficiency)
    
    atmost k
    
    eff[i] < eff[i+1] < eff[i+2] < eff[i+3] < ....... < eff[n-1]
    
    Pick atmost k Top most Speeds 
    
    */

class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        return mod(mod(a)+mod(b));
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i]={efficiency[i],speed[i]};
        }
        
        sort(vec.begin(),vec.end());
        
        ll max_perf = 0LL;
        
        ll sum_speed = 0LL;
        
        ll min_effi = 0LL;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        for(int i=n-1;i>=0;i--){
            
            min_effi = vec[i].first;
            
            ll curr_speed = vec[i].second;
            
            if(pq.size()<k){
                
                pq.push(curr_speed);
                
                sum_speed += curr_speed;
                
                max_perf = max(max_perf,(sum_speed*min_effi));
                
            }
            
            else if(!pq.empty() && pq.top() < curr_speed){
                
                sum_speed -= pq.top();
                pq.pop();
                
                sum_speed += curr_speed;
                pq.push(curr_speed);
                
                max_perf = max(max_perf,(sum_speed*min_effi));
                
            }
            
        }
        
        return mod(max_perf);
        
    }
};