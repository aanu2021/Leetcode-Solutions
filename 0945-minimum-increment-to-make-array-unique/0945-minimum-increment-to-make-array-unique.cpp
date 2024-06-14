class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        sort(nums.begin(),nums.end());
        int prev = -1;
        for(int i=0;i<n;i++){
            int req = max(nums[i], prev + 1);
            if(nums[i] == req){
                prev = nums[i];
                continue;
            }
            else{
                ops += (req - nums[i]);
                prev = req;
                continue;
            }
        }
        return ops;
    }
};

// 1 1 2 2 3 7
// 1 2 3 4 5 7    
    