class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxProd = nums[k];
        int left  = k-1;
        int right = k+1;
        int minEle = nums[k];
        while(left >= 0 || right < n){
            if(left >= 0 && right < n){
                if(nums[left] >= nums[right]){
                    minEle = min(minEle, nums[left]);
                    left--;
                }
                else{
                    minEle = min(minEle, nums[right]);
                    right++;
                }
                maxProd = max(maxProd, minEle*(right-left-1));
            }
            else if(left >= 0){
                minEle = min(minEle, nums[left]);
                left--;
                maxProd = max(maxProd, minEle*(right-left-1));
            }
            else{
                minEle = min(minEle, nums[right]);
                right++;
                maxProd = max(maxProd, minEle*(right-left-1));
            }
        }
        return maxProd;
    }
};