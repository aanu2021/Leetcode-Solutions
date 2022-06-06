class Solution {
public:
    
    typedef long long ll;
    
    int minMoves(vector<int>& nums, int k) {
        
        ll n=nums.size();
        
        vector<ll>A;
        
        for(ll i=0;i<n;i++){
            if(nums[i]==1){
                A.push_back(i);
            }
        }
        
        n=A.size();
        
        vector<ll>prefix(n,0LL);
        
        prefix[0]=A[0];
        
        for(ll i=1;i<n;i++){
            prefix[i]=prefix[i-1]+A[i];
        }
        
        ll ans=1e18;
        
        ll subtract=0;
        
        if(k%2==0){
            
            ll K=k/2;
            subtract=((K*(K+1))/2)+((K*(K-1))/2);
            
        }
        
        else{
            
            ll K=k/2;
            subtract=(K*(K+1));
            
        }
        
        for(ll i=0;i<=n-k;i++){
            
            if(k%2==0){
                
                ll right=prefix[i+k-1]-(i+(k/2)-1>=0 ? prefix[i+(k/2)-1] : 0LL);
                ll left=(i+(k/2)-1>=0 ? prefix[i+(k/2)-1] : 0LL)-(i-1>=0 ? prefix[i-1] : 0LL);
                
                ll curr=right-left-subtract;
                
                ans=min(ans,curr);
                
               // cout<<left<<" "<<right<<" "<<subtract<<endl;
                
            }
            
            else{
                
                ll right=prefix[i+k-1]-(i+(k/2)>=0 ? prefix[i+(k/2)] : 0LL);
                ll left=(i+(k/2)-1>=0 ? prefix[i+(k/2)-1] : 0LL)-(i-1>=0 ? prefix[i-1] : 0LL);
                ll curr=right-left-subtract;
                
                ans=min(ans,curr);
                
            }
            
        }
        
        return ans;
        
    }
};