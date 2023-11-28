class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int numberOfWays(string s) {
        int n = s.length();
        int cntSeat = 0;
        for(char ch : s){
            if(ch == 'S') cntSeat++;
        }
        if(cntSeat == 0 || cntSeat%2) return 0;
        ll ways = 1LL;
        int cnt = 0;
        int prevIndex = -1;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == 'S'){
                if(cnt == 2){
                    ways *= (ll)(i-prevIndex);
                    ways %= M;
                    cnt = 1;
                }
                else{
                    cnt++;
                }
                prevIndex = i;
            }
        }
        return ways;
    }
};