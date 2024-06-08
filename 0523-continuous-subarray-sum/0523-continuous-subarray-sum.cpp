class Solution {
public:
    
    typedef long long ll;
    
    bool checkSubarraySum(vector<int>& nums, int k) {
        ll currSum = 0LL;
        int n = nums.size();
        unordered_map<int,int>freq;
        freq[0] = -1;
        for(int i=0;i<n;i++){
            currSum += (ll)nums[i];
            currSum %= k;
            currSum += k;
            currSum %= k;
            if(freq.find(currSum) != freq.end()){
                if(i - freq[currSum] > 1) return true;
            }
            else{
                freq[currSum] = i;
            }
        }
        return false;
    }
};

// 23 + 2 + 4 = 29
    
//     29%6 = 5
//     23%6 = 5
    