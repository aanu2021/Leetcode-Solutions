class Solution {
public:
    
    typedef long long ll;
    
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        unordered_set<string>S;
        for(string &str : ideas){
            S.insert(str);
        }
        ll ans = 0LL;
        vector<vector<ll>>dp(26,vector<ll>(26,0LL));
        for(string &str:ideas){
            for(char ch='a';ch<='z';ch++){
                string temp = str;
                temp[0] = ch;
                if(S.find(temp)==S.end()){
                    dp[str[0]-'a'][ch-'a']++;
                }
            }
        }
        for(int x=0;x<26;x++){
            for(int y=0;y<26;y++){
                ans += dp[x][y]*dp[y][x];
            }
        }
        return ans;
    }
};


