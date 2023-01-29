class Solution {
public:
    
    typedef long long ll;
    
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums[i]--;
        }
        vector<vector<int>>left(n+5,vector<int>(n+5,0));
        vector<vector<int>>right(n+5,vector<int>(n+5,0));
        
        for(int i=0;i<n;i++){
            left[i][nums[i]]++;
            right[i][nums[i]]++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                left[i][j] += left[i-1][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                left[i][j] += left[i][j-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                right[i][j] += right[i+1][j];
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                right[i][j] += right[i][j+1];
            }
        }
        
        ll ans = 0LL;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                if(nums[i] < nums[j]) continue;
                ll leftCnt = 0LL;
                ll rightCnt = 0LL;
                if(nums[j] - 1 >= 0){
                    leftCnt = (ll)(left[i-1][nums[j]-1]);
                }
                if(nums[i] + 1 < n){
                    rightCnt = (ll)(right[j+1][nums[i]+1]);
                }
                ans += (ll)(leftCnt*rightCnt);
            }
        }
        return ans;
    }
};

