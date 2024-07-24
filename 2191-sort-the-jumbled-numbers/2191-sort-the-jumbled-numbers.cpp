class Solution {
public:
    
    typedef long long ll;
    
    ll replaced_num(vector<int>&map,ll n){
        
        ll num=n;
        
        string s="";
        
        if(num==0LL){
            return map[num];
        }
        
        while(n){
            
            ll rem=n%10;
            
            s+=to_string(map[rem]);
            
            n/=10;
            
        }
        
        reverse(s.begin(),s.end());
        
        ll currele=0LL;
        
        for(ll i=0;i<s.length();i++){
            currele=(currele*10)+(s[i]-'0');
        }
        
        return currele;
        
    }
    
    
    bool static comp(const pair<ll,ll>&x,const pair<ll,ll>&y){
        
        if(x.first==y.first){
            return x.second < y.second;
        }
        
        return x.first < y.first;
        
    }
    
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) {
        
        vector<pair<ll,ll>>vec;
        
        for(ll i=0;i<nums.size();i++){
            
            ll ele=(ll)nums[i];
            ll rele=replaced_num(map,ele);
            
            vec.push_back({rele,i});
            
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        vector<int>ans;
        
        for(ll i=0;i<vec.size();i++){
            
            ans.push_back(nums[vec[i].second]);
            
        }
        
        return ans;
        
    }
};