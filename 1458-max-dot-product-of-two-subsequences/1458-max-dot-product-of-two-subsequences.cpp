class Solution {
public:
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int firstMin  = INT_MAX;
        int firstMax  = INT_MIN;
        int secondMin = INT_MAX;
        int secondMax = INT_MIN;
        for(int i=0;i<m;i++){
            firstMin = min(firstMin, nums1[i]);
            firstMax = max(firstMax, nums1[i]);
        }
        for(int i=0;i<n;i++){
            secondMin = min(secondMin, nums2[i]);
            secondMax = max(secondMax, nums2[i]);
        }
        if(firstMax < 0 && secondMin > 0){
            return (firstMax*secondMin);
        }
        if(firstMin > 0 && secondMax < 0){
            return (firstMin*secondMax);
        }
        vector<int>prev(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;j++){
                curr[j] = (nums1[i-1]*nums2[j-1]) + prev[j-1];
                curr[j] = max(curr[j], curr[j-1]);
                curr[j] = max(curr[j], prev[j]);
            }
            for(int j=0;j<=n;j++){
                prev[j] = curr[j];
            }
        }
        return prev[n];
    }
};