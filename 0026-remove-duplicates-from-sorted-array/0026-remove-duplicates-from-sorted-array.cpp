class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int k = 0;
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n && nums[j]==nums[i]){
                j++;
            }
            nums[k++] = nums[i];
            i=j;
            i--;
        }
        return k;
        
    }
};