class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++) freq[nums[i]]++;
        for(auto &itr : freq){
            int ele = itr.first;
            int occ = itr.second;
            if(occ == 1) return -1;
            if(occ%3 == 0){
                ops += (occ/3);
            }
            else if(occ%3 == 1){
                ops += (2 + ((occ-4)/3));
            }
            else{
                ops += (1 + ((occ-2)/3));
            }
        }
        return ops;
    }
};

