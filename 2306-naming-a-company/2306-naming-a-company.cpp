class Solution {
public:
    
    typedef long long ll;
    
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        ll ans = 0LL;
        vector<unordered_set<string>>initialGrp(26);
        for(string &str : ideas){
            initialGrp[str[0]-'a'].insert(str.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                ll mutualGroups = 0LL;
                for(auto &str : initialGrp[i]){
                    if(initialGrp[j].find(str) != initialGrp[j].end())
                    {
                        mutualGroups++;
                    }
                }
                ll distinct_first_set = (ll)initialGrp[i].size();
                ll distinct_second_set = (ll)initialGrp[j].size();
                distinct_first_set -= mutualGroups;
                distinct_second_set -= mutualGroups;
                ans += 2LL*distinct_first_set*distinct_second_set;
            }
        }
        return ans;
    }
};