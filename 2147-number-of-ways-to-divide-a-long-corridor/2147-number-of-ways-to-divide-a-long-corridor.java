class Solution {
    
    final long MOD = 1000000007;
    
    public int numberOfWays(String s) {
        int n = s.length();
        int cntSeat = 0;
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            if(ch == 'S') cntSeat++;
        }
        if(cntSeat == 0 || cntSeat%2 != 0) return 0;
        long ways = 1L;
        int cnt = 0;
        int prevIndex = -1;
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            if(ch == 'S'){
                if(cnt == 2){
                    ways *= (long)(i-prevIndex);
                    ways %= MOD;
                    cnt = 1;
                }
                else{
                    cnt++;
                }
                prevIndex = i;
            }
        }
        return (int)ways;
    }
}