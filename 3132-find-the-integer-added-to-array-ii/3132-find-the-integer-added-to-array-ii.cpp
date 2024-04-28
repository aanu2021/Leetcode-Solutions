class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n = nums1.size();
        int minDiff = INT_MAX;
        for(int i1=0;i1<n;i1++){
            for(int i2=i1+1;i2<n;i2++){
                int p1 = 0;
                int p2 = 0;
                unordered_set<int>S;
                for(int i=0;i<n-2;i++){
                    while(p1 < n && (p1 == i1 || p1 == i2)){
                        p1++;
                    }
                    S.insert(nums2[i] - nums1[p1]);
                    p1++;
                }
                if(S.size() == 1){
                    minDiff = min(minDiff, *S.begin());
                }
            }
        }
        return minDiff;
    }
};

// 4 8 12 16 20
// 10 14 18    