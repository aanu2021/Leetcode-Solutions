class Solution {
public:
    
    int lcm(int a,int b){
        return (a*b)/__gcd(a,b);
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>L[n];
        L[0][nums[0]]++;
        for(int i=1;i<n;i++){
            L[i][nums[i]]++;
            for(auto &it : L[i-1]){
                int currlcm = lcm(it.first,nums[i]);
                if(k%currlcm == 0){
                    L[i][currlcm] += it.second;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(auto &it : L[i]){
                if(it.first == k) ans += it.second;
            }
        }
        return ans;
    }
};