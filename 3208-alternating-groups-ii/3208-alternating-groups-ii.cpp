class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        if(k == 1) return nums.size();
        int answer = 0, altLen = 1, i = 1, n = nums.size();
 
        for(;i <= n+k-2; ){
            int index = i, prevIndex = i-1;
            if(index >= n) index -= n;
            if(prevIndex >= n) prevIndex -= n;
            if(nums[prevIndex] == nums[index]) altLen = 1;
            else altLen++;
            if(altLen > k-1) answer++;
            i++;
        } 
        
        return answer;

    }
};

// a0 a1 a2 a3 a4 a0 a1