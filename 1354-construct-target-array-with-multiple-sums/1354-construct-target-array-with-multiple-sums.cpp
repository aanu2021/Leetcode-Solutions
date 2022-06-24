class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>& target) {
        
        ll n=target.size();
        
        priority_queue<ll>pq;
        
        ll sum=0LL;
        
        for(ll i:target){
            sum+=i;
            pq.push(i);
        }
        
        while(pq.top()!=1){
            
            ll maxi=pq.top();
            pq.pop();
            
            ll rest_of_sum=(sum-maxi);
            
            if(rest_of_sum<=0 || maxi<=0 || sum<=0 || rest_of_sum>=maxi){
                
                return false;
                
            }
            
            ll val_to_insert=(maxi%rest_of_sum);
            
            if(val_to_insert==0){
                val_to_insert=rest_of_sum;
            }
            
            sum-=maxi;
            sum+=val_to_insert;
            
            pq.push(val_to_insert);
            
        }
        
        return true;
        
    }
};