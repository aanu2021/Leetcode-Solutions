class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<int>>prefix(n,vector<int>(26,0));
        vector<vector<int>>suffix(n,vector<int>(26,0));
        vector<vector<int>>dp(26,vector<int>(26,0));
        for(int i=0;i<n;i++){
            prefix[i][s[i]-'a']++;
            suffix[i][s[i]-'a']++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<26;j++){
                suffix[i][j] += suffix[i+1][j];
            }
        }
        for(int i=0;i<n;i++){
            char ch = s[i];
            int x = (int)(ch-'a');
            for(int j=0;j<26;j++){
                int leftOcc = (i-1 >= 0 ? prefix[i-1][j] : 0);
                int rightOcc = (i+1 < n ? suffix[i+1][j] : 0);
                if(leftOcc > 0 && rightOcc > 0){
                    dp[x][j]++;
                }
            }
        }
        int answer = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(dp[i][j]) answer++;
            }
        }
        return answer;
    }
};

// b b c b a b a


// a a -> 
// a b -> 1
// a c -> 
// b a -> 1
// b b -> 1
// b c ->
// c a -> 
// c b -> 1
// c c -> 


