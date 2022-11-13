class Solution {
public:
    
    int lcm(int a,int b){
        return (a*b)/__gcd(a,b);
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>prev;
        for(int i=0;i<n;i++){
            prev[nums[i]]++;
            unordered_map<int,int>curr;
            for(auto &itr:prev){
                int ele = itr.first;
                int occ = itr.second;
                int curr_lcm = lcm(ele,nums[i]);
                if(curr_lcm==k){
                    ans+=occ;
                }
                if(k%curr_lcm==0){
                    curr[curr_lcm]+=occ;
                }
            }
            swap(prev,curr);
        }
        return ans;
    }
};