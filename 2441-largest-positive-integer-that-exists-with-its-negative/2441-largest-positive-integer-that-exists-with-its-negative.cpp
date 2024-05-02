class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>S;
        int maxi = -1;
        for(int &ele : nums){
            if(ele > 0){
                if(S.find(-ele) != S.end()){
                    maxi = max(maxi, ele);
                }
            }
            else{
                if(S.find(-ele) != S.end()){
                    maxi = max(maxi, -ele);
                }
            }
            S.insert(ele);
        }
        return maxi;
    }
};