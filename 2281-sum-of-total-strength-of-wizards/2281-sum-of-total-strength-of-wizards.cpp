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
    
    int totalStrength(vector<int>& arr) {
        
        ll n=arr.size();
        
        ll ans=0LL;
        
        stack<ll>st;
        
        vector<ll>left(n,-1);
        vector<ll>right(n,n);
        
        for(ll i=0;i<n;i++){
            
            if(st.empty()){
                st.push(i);
                left[i]=-1;
                continue;
            }
            
            if(arr[st.top()]<arr[i]){
                left[i]=st.top();
                st.push(i);
            }
            
            else{
                
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                
                if(!st.empty()){
                    left[i]=st.top();
                }else{
                    left[i]=-1;
                }
                
                st.push(i);
                
            }
            
        }
        
        
        while(!st.empty()){
            st.pop();
        }
        
        
         for(ll i=n-1;i>=0;i--){
            
            if(st.empty()){
                st.push(i);
                right[i]=n;
                continue;
            }
            
            if(arr[st.top()]<=arr[i]){
                right[i]=st.top();
                st.push(i);
            }
            
            else{
                
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                
                if(!st.empty()){
                    right[i]=st.top();
                }else{
                    right[i]=n;
                }
                
                st.push(i);
                
            }
            
        }
        
      
        
        vector<ll>preSum(n+1,0LL);
        vector<ll>prePrefix(n+2,0LL);
        
        for(ll i=0;i<n;i++){
            preSum[i+1]=add(preSum[i],(ll)arr[i]);
        }
        
        for(ll i=0;i<=n;i++){
            prePrefix[i+1]=add(prePrefix[i],preSum[i]);
        }
        
        
        for(ll i=0;i<n;i++){
            
            ll curr1=mul(prePrefix[right[i]+1]-prePrefix[i+1],(i-left[i]));
            
            ll curr2=mul(prePrefix[i+1]-prePrefix[left[i]+1],(right[i]-i));
            
            ll ele=((curr1-curr2)%M+M)%M;
            
            ll curr=mul((ll)arr[i],ele);
            
            ans=add(ans,curr);
            
        }
        
        return ans;
        
    }
};