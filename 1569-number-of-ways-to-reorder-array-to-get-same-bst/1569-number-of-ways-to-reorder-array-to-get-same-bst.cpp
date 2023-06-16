class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll fact[2002];
    
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
        if(b==0) return 1LL;
        if(b==1) return a;
        ll res = 1LL;
        while(b){
            if(b%2) res = mul(res,a);
            b/=2;
            a=mul(a,a);
        }
        return res;
    }
    ll inv(ll a){
        return modPow(a,M-2);
    }
    ll nck(int n,int k){
        return mul(mul(fact[n],inv(fact[n-k])),inv(fact[k])); 
    }
    void factFind(){
        memset(fact,0LL,sizeof(fact));
        fact[0] = 1LL;
        for(int i=1;i<=2000;i++){
            fact[i] = mul(fact[i-1],(ll)i);
        }
    }
    
    ll dfs(vector<int>&nums){
        
        int n = nums.size();
        
        if(n <= 1) return 1LL;
        
        vector<int>left,right;
        
        for(int i=1;i<n;i++){
            if(nums[i] > nums[0]){
                right.push_back(nums[i]);
            }
            else{
                left.push_back(nums[i]);
            }
        }
        
        int c1 = left.size();
        int c2 = right.size();
        
        ll answer = mul(dfs(left),dfs(right));
        answer = mul(answer,nck(c1+c2,c1));
        
        return answer;
        
    }
    
    int numOfWays(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1) return 0;
        
        factFind();
        
        ll answer = dfs(nums);
        
        answer--;
        answer += M;
        answer %= M;
        
        return answer;
        
    }
};

/*

3 1 2 5 4 6
    
1 2
5 4 6
    
1 3 2
 
3 4 2 5    
    
2 3
4 5
    
5 4 6
    
    
    
1
 \   
  3
 /
2_ _ _ _ _    
  
*/