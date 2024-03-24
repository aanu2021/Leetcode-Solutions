class Solution {
public:
    
    typedef long long ll;
    
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& f) {
        multiset<pair<ll,int>>ms;
        int n = nums.size();
        unordered_map<int,ll>freq;
        vector<ll>answer(n, 0);
        for(int i=0;i<n;i++){
            freq[nums[i]] = 0LL;
        }
        for(auto &itr : freq){
            ms.insert({itr.second, itr.first});
        }
        for(int i=0;i<n;i++){
            int ele = nums[i];
            ll occ = freq[ele];
            auto itr = ms.lower_bound({occ,ele});
            ms.erase(itr);
            occ += f[i];
            freq[ele] = occ;
            ms.insert({occ,ele});
            if(ms.size() > 0){
               auto last = ms.rbegin();
               ll occurence = (*last).first;
               answer[i] = occurence;   
            }
        }
        return answer;
    }
};


   