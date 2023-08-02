class Solution {
public:
    
    typedef long long ll;
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>>answer;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j != i+1 && nums[j]==nums[j-1]) continue;
                int low = j+1, high = n-1;
                while(low < high){
                    ll currSum = (ll)nums[i] + (ll)nums[j] + (ll)nums[low] + (ll)nums[high];
                    if(currSum == target){
                        answer.push_back({nums[i],nums[j],nums[low],nums[high]});
                        int leftEle = nums[low];
                        int rightEle = nums[high];
                        while(low < high && nums[low] == leftEle){
                            low++;
                        }
                        while(low < high && nums[high] == rightEle){
                            high--;
                        }
                    }
                    else if(currSum > target){
                        high--;
                    }
                    else{
                        low++;
                    }
                }
            }
        }
        
        return answer;
    }
};