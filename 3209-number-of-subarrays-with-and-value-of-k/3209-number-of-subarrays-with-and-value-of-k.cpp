class Solution {
public:
    
    typedef long long ll;
    
    unordered_map<ll,ll>p;
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        ll answer = 0LL;
        
        p.clear();
        
        for(int i=0;i<nums.size();i++){
            unordered_map<ll,ll>c;
            c[nums[i]] = 1LL;
            if(nums[i] < k || nums[i] > k){
                
            }
            else{
                answer++;
            }
            for(auto &itr : p){
                ll pval = itr.first & (ll)nums[i];
                if(pval == (ll)k) answer += itr.second;
                if(pval < (ll)k) continue;
                c[pval] += itr.second;
            }
            p = c;
        }
        
        return answer;
    }
};

// 1 1 2
// 0 1 2

// 1 + 2 + 3 = 6
    
    
    
// k = 1
// k = 0    
    