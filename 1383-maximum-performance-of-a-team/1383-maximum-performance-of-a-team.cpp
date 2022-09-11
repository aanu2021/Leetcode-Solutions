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
        
        vector<pair<int,int>>vec;
        
        for(int i=0;i<n;++i){
            
            vec.push_back({efficiency[i],speed[i]});
            
        }
        
        sort(vec.begin(),vec.end());
        
        ll sum=0LL;
        
        ll ans=0LL;
        
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        
        for(int i=n-1;i>=0;i--){
            
            int speedi=vec[i].second;
            int efficiencyi=vec[i].first;
            
            if(pq.size()<k){
                
                pq.push(speedi);
                
                sum+=speedi;
                
                ans=max(ans,(sum*efficiencyi));
                
               // cout<<sum<<" "<<efficiencyi<<"\n";
                
            }
            
            else{
                
                if(!pq.empty() && pq.top()<(ll)speedi){
                    
                    sum-=pq.top();
                    pq.pop();
                    
                    pq.push(speedi);
                    
                    sum+=speedi;
                    
                    ans=max(ans,(sum*efficiencyi));
                    
                  //  cout<<sum<<" "<<efficiencyi<<"\n";
                    
                }
                
                
            }
            
        }
        
        return mod(ans);
        
    }
};