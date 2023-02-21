class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] < nums[n-1]) return nums[0];
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(low == high) return nums[low];
            if(nums[low] < nums[high]) return nums[low];
            if(mid-1>=0 && nums[mid-1]>nums[mid]) return nums[mid];
            if(mid+1< n && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[low] == nums[high]){
                low++;
            }
            else if(nums[low] <= nums[mid]){
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

3,3,3,3,3,3,1,2,3
0 1 2 3 4 5 6 7 8

low = 2
high = 8

2,2,2,0,1

l = 0
r = 4
m = 2

2,0,0,1,2

3,3,3,3,3,3,1,2,2,3
0 1 2 3 4 5 6 7 8 9
         
l = 5
r = 8
m = 6

[low......mid.......high]

[low........mid....m...high]
if(nums[low] <= nums[mid])  minimum value must lie on the right half

[low....m...mid........high]
if(nums[mid] <= nums[high]) minimum value must lie on the left half

Base Case : low == high                single element
            nums[low] < nums[high]     already sorted array
            nums[mid] > nums[mid+1]    inflation point
            nums[mid-1] > nums[mid]    inflation point

nums[low] == nums[high] case : [ 2,0,1,2,2,2 ]

Deci Case : nums[low] == nums[high]  high--          Can't decide
            nums[low] <= nums[mid]   low = mid + 1   min is on right
            nums[mid] <= nums[high]  high = mid - 1  min is on left
                                 
T.C : O(N) / O(logN)
S.C : O(1)

*/

