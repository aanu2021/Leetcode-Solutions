class Solution {
public:

    double getMedian(int x,int y){
        return (x+y)/2.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2,nums1);
        int low = 0, high = m;
        while(low <= high){
            int mid = (low + high)/2;
            int partX = mid;
            int partY = (m+n+1)/2;
            partY -= partX;
            int maxLeftX  = INT_MIN;
            int maxLeftY  = INT_MIN;
            int minRightX = INT_MAX;
            int minRightY = INT_MAX;
            if(partX != 0) maxLeftX =  nums1[partX-1];
            if(partY != 0) maxLeftY =  nums2[partY-1];
            if(partX != m) minRightX = nums1[partX];
            if(partY != n) minRightY = nums2[partY];
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                if((m+n)%2){
                    return max(maxLeftX, maxLeftY);
                }
                else{
                    return getMedian(max(maxLeftX, maxLeftY), min(minRightX, minRightY));   
                }
            }
            else if(maxLeftX > minRightY){
                high = partX - 1;
            }
            else{
                low = partX + 1;
            }
        }
        return -1.0;
    }
};

/*

[1,4,4,7]
[2,3,5,6]

[1,2,3,4,4,5,6,7] = (4 + 4) / 2

req = 4
low = 0
high = 4
partX = 2
partY = 2

4 4
3 5 

4 7
2 3

median = (m+n+1)/2  th element


*/
