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
    
    ll kadane(vector<int>&arr){
        
        ll n=arr.size();
        
        ll maxsum=0LL;
        
        ll currsum=0LL;
        
        for(ll i=0;i<n;i++){
            
            currsum+=(ll)arr[i];
            
            maxsum=max(maxsum,currsum);
            
            if(currsum<0){
                currsum=0;
            }
            
        }
        
        return maxsum;
        
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        ll n=arr.size();
        
        if(k==1){
            return kadane(arr);
        }
        
        vector<int>temp=arr;
        
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        
        ll sum=accumulate(arr.begin(),arr.end(),0LL);
        
        if(sum>=0){
            
            return add(kadane(temp),mul(k-2,sum));
            
        }
        
        else{
            
            return kadane(temp);
            
        }
        
    }
};