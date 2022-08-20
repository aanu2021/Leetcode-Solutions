class Solution {
public:
    
    typedef long long ll;
    
    vector<ll>Parent;
    
    vector<ll>Size;
    
    ll find(ll x){
        
        if(Parent[x]==x){
            return x;
        }
        
        ll temp=find(Parent[x]);
        
        return Parent[x]=temp;
        
    }
    
    void Union(ll x,ll y){
        
        ll lx=find(x);
        ll ly=find(y);
        
        if(lx!=ly){
            
            if(Size[lx]>Size[ly]){
                Size[lx]+=Size[ly];
                Parent[ly]=lx;
            }
            
            else{
                Size[ly]+=Size[lx];
                Parent[lx]=ly;
            }
            
        }
        
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& queries) {
        
        ll n=nums.size();
        
        ll m=queries.size();
        
        Parent.resize(n);
        
        Size.resize(n);
        
        for(ll i=0;i<n;++i){
            
            Parent[i]=i;
            Size[i]=0;
            
        }
        
        vector<ll>ans(m,0LL);
        
        vector<ll>arr(n,0);
        
        map<ll,ll>mp;
        
        for(ll i:queries){
            mp[i]++;
        }
        
        for(ll i=0;i<n;++i){
            
            if(mp[i]==0){
                arr[i]=nums[i];
            }else{
                arr[i]=0;
                continue;
            }
            
        }
        
        
        ll curr_max_sum=0LL;
        
        for(ll i=0;i<n;++i){
            
            if(arr[i]==0){
                continue;
            }
            
            ll j=i;
            
            ll currsum=0LL;
            
            while(j<n && arr[j]!=0){
                
                Size[j]=nums[j];
                Union(i,j);
                currsum+=arr[j];
                j++;
                
            }
            
            curr_max_sum=max(curr_max_sum,currsum);
            
            i=j;
            i--;
            
        }
        
        
        // cout<<curr_max_sum<<"\n";
        
        ll idx=m-1;
        
        ans[idx]=curr_max_sum;
        
        for(ll i=idx;i>=1;i--){
            
            ll curridx=queries[i];
            
            Size[curridx]=nums[curridx];
            
            arr[curridx]=nums[curridx];
            
            if(curridx+1<n && arr[curridx+1]!=0LL){
                
                Union(curridx,curridx+1);
                
            }
            
            if(curridx-1>=0 && arr[curridx-1]!=0LL){
                
                Union(curridx,curridx-1);
                
            }
            
            ll par=find(curridx);
            
            ans[i-1]=max(Size[par],curr_max_sum);
            
            curr_max_sum=max(curr_max_sum,Size[par]);
            
        }
        
        return ans;
        
    }
};