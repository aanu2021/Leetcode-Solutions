class Solution {
public:
    
    typedef long long ll;
    
    long long distinctNames(vector<string>& ideas) {
        ll ans = 0LL;
        vector<unordered_set<string>>initialGrp(26);
        for(string &str : ideas){
            initialGrp[str[0]-'a'].insert(str.substr(1));
        }
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                ll mutualGrp = 0LL;
                for(auto &str : initialGrp[i]){
                    if(initialGrp[j].count(str)){
                        mutualGrp++;
                    }
                }
                ll distinct_first_set = (ll)initialGrp[i].size();
                ll distinct_second_set = (ll)initialGrp[j].size();
                distinct_first_set -= mutualGrp;
                distinct_second_set -= mutualGrp;
                ans += (2LL * distinct_first_set * distinct_second_set);
            }
        }
        return ans;
    }
};