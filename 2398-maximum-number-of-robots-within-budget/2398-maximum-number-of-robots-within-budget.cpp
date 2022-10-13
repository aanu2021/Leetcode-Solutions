class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>&charge,vector<int>&run,ll budget,vector<ll>&prefix,ll k){
        
        ll n=charge.size();
        
        ll sum=0LL;
        
        deque<ll>q;
        
        vector<ll>ans;
        
        for(ll i=0;i<k;++i){
            
            while(!q.empty() && charge[q.back()]<=charge[i]){
                
                q.pop_back();
                
            }
            
            q.push_back(i);
            
        }
        
        ans.push_back(charge[q.front()]);
        
        for(ll i=k;i<n;++i){
            
            while(!q.empty() && q.front()<=i-k){
                
                q.pop_front();
                
            }
            
            while(!q.empty() && charge[q.back()]<=charge[i]){
                
                q.pop_back();
                
            }
            
            q.push_back(i);
            
            ans.push_back(charge[q.front()]);
            
        }
        
        ll maxvalue=0LL;
        
        for(ll i=k-1;i<n;++i){
            
            ll currsum=prefix[i]-(i-k>=0 ? prefix[i-k] : 0LL);
            
            ll currmax=ans[i-k+1];
            
            ll currvalue=currmax+(k*currsum);
            
            if(currvalue<=budget){
                return true;
            }
            
        }
        
        return false;
        
    }
    
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        
        ll n=charge.size();
        
        ll low=1,high=n;
        
        ll ans=0LL;
        
        vector<ll>prefix(n,0LL);
        
        prefix[0]=(ll)run[0];
        
        for(ll i=1;i<n;++i){
            
            prefix[i]=prefix[i-1]+(ll)run[i];
            
        }
        
        while(low<=high){
            
            ll mid=(low+high)/2;
            
            if(isPossible(charge,run,budget,prefix,mid)){
                
                ans=mid;
                low=mid+1;
                
            }
            
            else{
                
                high=mid-1;
                
            }
            
        }
        
        return ans;
        
    }
};