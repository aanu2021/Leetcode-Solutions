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
    
    int sumSubarrayMins(vector<int>& arr) {
        
        ll n=arr.size();
        
        vector<ll>left(n,-1);
        vector<ll>right(n,n);
        
        stack<ll>st;
        
        for(ll i=0;i<n;i++){
            
            if(st.empty()){
                
                left[i]=-1;
                st.push(i);
                continue;
                
            }
            
            if(arr[st.top()]<=arr[i]){
                left[i]=st.top();
                st.push(i);
            }
            
            else{
                
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    left[i]=-1;
                }else{
                    left[i]=st.top();
                }
                
                st.push(i);
                
            }
            
        }
        
        
        while(!st.empty()){
            st.pop();
        }
        
        
        for(ll i=n-1;i>=0;i--){
            
            if(st.empty()){
                
                right[i]=n;
                st.push(i);
                continue;
                
            }
            
            if(arr[st.top()]<arr[i]){
                right[i]=st.top();
                st.push(i);
            }
            
            else{
                
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    right[i]=n;
                }else{
                    right[i]=st.top();
                }
                
                st.push(i);
                
            }
            
        }
        
        
        ll ans=0LL;
        
//         for(ll i=0;i<n;i++){
            
//             cout<<left[i]<<" ";
            
//         }cout<<endl;
        
//         for(ll i=0;i<n;i++){
            
//             cout<<right[i]<<" ";
            
//         }cout<<endl;
//         cout<<endl;
        
        for(ll i=0;i<n;i++){
            
            ll lpart=(i-left[i]);
            ll rpart=(right[i]-i);
            
            ll curr=mul(lpart,rpart);
            curr=mul(curr,(ll)arr[i]);
            
            ans=add(ans,curr);
            
        }
        
        return ans;
        
    }
};