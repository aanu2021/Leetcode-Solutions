typedef long long ll;

const ll M = 1e9 + 7;

ll fact[200005];

bool prime[200005];

ll mod(ll a){
    return ((a%M)+M)%M;
}

ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}

ll modPow(ll a,ll b){
    
    if(b==0){
        return 1LL;
    }
    
    else if(b==1){
        return a;
    }
    
    ll res=1LL;
    
    while(b){
        
        if(b%2==1){
            res=mul(res,a);
        }
        
        b/=2;
        a=mul(a,a);
        
    }
    
    return res;
    
}

ll power(ll a,ll b){
    
    if(b == 0){
        return 1LL;
    }
    
    ll ans = power(a,b/2);
    
    ans *= ans;
    
    ans %= M;
    
    if(b % 2){
        ans *= a;
    }
    
    return ans % M;
    
}

ll inv(ll a){
    return modPow(a,M-2);
}

ll sum_of_x(ll x){
    
    return (x*(x+1))/2;
    
}

void sieve(){
    
    memset(prime,true,sizeof(prime));
    
    prime[0] = false;
    prime[1] = false;
    
    for(int i=2;i*i<=200000;i++){
        
        if(prime[i]){
            
            for(int j=i*i;j<=200000;j+=i){
                
                prime[j] = false;
                
            }
            
        }
        
    }
    
}

void factFind(){
    
    memset(fact,0LL,sizeof(fact));
    
    fact[0]=1LL;
    fact[1]=1LL;
    
    for(ll i=2;i<=200002;i++){
        fact[i]=mul(fact[i-1],i);
    }
    
}


class Solution {
public:
    bool static comp(const pair<int,int>&x,const pair<int,int>&y){
        return x.second > y.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n=plantTime.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i]={plantTime[i],growTime[i]};
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int start = 0,end = 0;
        
        for(int i=0;i<n;i++){
            start+=vec[i].first;
            end=max(end,start+vec[i].second);
        }
        
        return end;
        
    }
};

vector<ll>arr;
vector<ll>segMax;
vector<ll>segMin;

void BuildSeg(ll idx,ll low,ll high){
    
    if(low>high){
        return;
    }
    
    if(low==high){
        segMax[idx]=arr[low];
        segMin[idx]=arr[high];
        return;
    }
    
    else{
        
        ll mid=(low+high)/2;
        
        BuildSeg(2*idx+1,low,mid);
        BuildSeg(2*idx+2,mid+1,high);
        
        segMax[idx]=max(segMax[2*idx+1],segMax[2*idx+2]);
        segMin[idx]=min(segMin[2*idx+1],segMin[2*idx+2]);
        
    }
    
}


ll queryMax(ll idx,ll low,ll high,ll l,ll r){
    
    if(low>=l && high<=r){
        return segMax[idx];
    }
    
    if(low>r || high<l){
        return INT_MIN;
    }
    
    ll mid=(low+high)/2;
    
    ll left=queryMax(2*idx+1,low,mid,l,r);
    ll right=queryMax(2*idx+2,mid+1,high,l,r);
    
    return max(left,right);
    
}


ll queryMin(ll idx,ll low,ll high,ll l,ll r){
    
    if(low>=l && high<=r){
        return segMin[idx];
    }
    
    if(low>r || high<l){
        return INT_MAX;
    }
    
    ll mid=(low+high)/2;
    
    ll left=queryMin(2*idx+1,low,mid,l,r);
    ll right=queryMin(2*idx+2,mid+1,high,l,r);
    
    return min(left,right);
    
}