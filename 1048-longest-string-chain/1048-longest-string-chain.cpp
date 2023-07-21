class Solution {
public:
    
    bool static comp(const string&x, const string&y){
        return x.length() < y.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>dp;
        for(int i=0;i<n;i++){
            dp[words[i]] = 1;
        }
        int maxLen = 1;
        for(int i=1;i<n;i++){
            string str = words[i];
            int len = str.length();
            for(int j=0;j<len;j++){
                string pref = str.substr(0,j);
                string suff = str.substr(j+1);
                string curr = pref;
                curr += suff;
                dp[str] = max(dp[str], 1 + dp[curr]);
                maxLen = max(maxLen, dp[str]);
            }
        }
        return maxLen;
    }
};