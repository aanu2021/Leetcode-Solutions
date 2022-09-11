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
        
        for(int i=0;i<n;++i){
            
            vec[i]={efficiency[i],speed[i]};
            
        }
        
        sort(vec.begin(),vec.end());
        
        ll sum_speed=0LL;
        
        ll min_eff=0LL;
        
        ll maxi_per=0LL;
        
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=n-1;i>=0;i--){
            
            int curr_speed=vec[i].second;
            
            min_eff=(ll)vec[i].first;
            
            if(pq.size()<k){
                
                pq.push(curr_speed);
                
                sum_speed+=(ll)curr_speed;
                
                maxi_per=max(maxi_per,(sum_speed*min_eff));
                
            }
            
            else if(!pq.empty() && pq.top()<(ll)curr_speed){
                
                sum_speed-=(ll)pq.top();
                pq.pop();
                
                pq.push(curr_speed);
                sum_speed+=(ll)curr_speed;
                
                maxi_per=max(maxi_per,(sum_speed*min_eff));
                
            }
            
        }
        
        return mod(maxi_per);
        
    }
};