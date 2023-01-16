class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>G[n];
        G[0][nums[0]]++;
        int ans = 0;
        for(int i=1;i<n;i++){
            G[i][nums[i]]++;
            for(auto &it : G[i-1]){
                int new_gcd = __gcd(it.first,nums[i]);
                G[i][new_gcd] += it.second;
            }
        }
        for(int i=0;i<n;i++){
            for(auto &it : G[i]){
                if(it.first == k) ans += it.second;
            }
        }
        return ans;
    }
};

/*

9 3 1 2 6 3

G[i][k] --> stores number of subarrays ending at index i having
            gcd equal to K;
    
G[0][9] = 1
    
G[1][3] = 2
    
G[2][1] = 3
    
G[3][2] = 1
G[3][1] = 3
    
G[4][6] = 1
G[4][2] = 1
G[4][1] = 3
    
G[5][3] = 2
G[5][1] = 4

*/