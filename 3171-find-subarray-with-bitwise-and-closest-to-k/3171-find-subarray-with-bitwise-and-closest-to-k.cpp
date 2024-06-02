class Solution {
public:
    
    int getAndSum(vector<vector<int>>&bits, int l, int r){
        int andSum = 0;
        for(int i=0;i<32;i++){
            int bitCnt = bits[r][i] - (l > 0 ? bits[l-1][i] : 0);
            if(bitCnt == (r-l+1)){
                andSum |= (1<<i);
            }
        }
        return andSum;
    }
    
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>bits(n, vector<int>(32, 0));
        for(int i=0;i<n;i++){
            int ele = nums[i];
            for(int j=0;j<32;j++){
                if((ele&(1<<j))){
                    bits[i][j]++;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<32;j++){
                bits[i][j] += bits[i-1][j];
            }
        }
        int l = 0, r = 0;
        int answer = INT_MAX;
        while(r < n){
            while(l <= r && getAndSum(bits, l, r) < k){
                answer = min(answer, abs(k - getAndSum(bits, l, r)));
                l++;
            }
            answer = min(answer, abs(k - getAndSum(bits, l, r)));
            r++;
        }
        return answer;
    }
};