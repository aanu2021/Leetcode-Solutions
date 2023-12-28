class Solution {
public:
    
    int dp[102][102];
    
    int calc(int x){
        if(x == 1) return 0;
        if(x < 10) return 1;
        if(x < 100) return 2;
        else return 3;
    }
    
    int func(string &s, int left, int k, int n){
        if(k < 0) return 1000000;
        if(left == n) return 0;
        if(n-left <= k) return 0;
        if(dp[left][k] != -1) return dp[left][k];
        int answer = 1000000;
        int maxFreq = 0;
        int cnt[26] = {0};
        for(int right=left;right<n;right++){
            cnt[s[right]-'a']++;
            maxFreq = max(maxFreq, cnt[s[right]-'a']);
            answer = min(answer, 1 + calc(maxFreq) + func(s,right+1,k-(right-left+1-maxFreq),n));
        }
        return dp[left][k] = answer;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        int ans = func(s,0,k,n);
        return ans;
    }
};


// Greedy Approach : Generate the small substrings with maximum occuring character

// a b a c a a b a 
         


