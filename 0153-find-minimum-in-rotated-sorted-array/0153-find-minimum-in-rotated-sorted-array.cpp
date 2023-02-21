class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        if(nums[0] <= nums[n-1]) return nums[0];
        
        int low = 0, high = n-1;
        
        while(low <= high){
            
            int mid = (low + high)/2;
            
            if(nums[low] <= nums[high]) return nums[low];
            if(mid-1>=0 && nums[mid-1]>nums[mid]) return nums[mid];
            if(mid+1 <n && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[low] <= nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        
        return -1;
        
    }
};

/*

3 4 5 6 1 2
0 1 2 3 4 5

l = 0
r = 5
m = 2

Observation : 

For inflection points , we need to check two simple conditions , if they are met , then simple return the minimum value , otherwise go for binary search.

nums[i] < nums[i+1] --> nums[i] > nums[i+1]

here i,i+1 are the inflection points , of we arrive at either of these two points , then it is trivial to return the minimum element.

Excluding inflection points , all the remaining elements , there might be two possibilities.

either , nums[low] <= nums[mid]
or     , nums[mid] <= nums[high]

low,.....,mid,...m...,high   ==>  nums[low] <= nums[mid]
low,.m,...mid,.......,high   ==>  nums[mid] <= nums[high]


*/