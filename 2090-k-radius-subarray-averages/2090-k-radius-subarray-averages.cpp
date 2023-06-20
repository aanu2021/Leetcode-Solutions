class Solution {
public:
    
    typedef long long ll;
    
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(k==0){
            return nums;
        }
        
        int L = (2*k) + 1;
        
        ll currSum = 0LL;
        
        vector<int>answer(n,-1);
        
        for(int i=0;i<n;i++){
            currSum += (ll)nums[i];
            if((i+1) >= L){
                answer[i-k] = (int)(currSum/L);
                currSum -= (ll)nums[i-L+1];
            }
        }
        
        return answer;
        
    }
};