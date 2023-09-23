class Solution {
public:
    
    bool static comp(const string &x,const string &y){
        return x.length() < y.length();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int>dp;
        int maxLen = 0;
        for(int i=0;i<n;i++){
            string str = words[i];
            for(int j=0;j<str.length();j++){
                string pstr = str.substr(0,j);
                pstr += str.substr(j+1);
                dp[str] = max(dp[str], 1 + dp[pstr]);
                maxLen = max(maxLen, dp[str]);
            }
        }
        return maxLen;
    }
};