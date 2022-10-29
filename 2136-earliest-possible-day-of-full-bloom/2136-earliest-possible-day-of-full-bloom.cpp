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