class Solution {
public:
    
    typedef long long ll;
    
    int minimizeArrayValue(vector<int>& nums) {
        
        int n = nums.size();
        ll maxi = -1e18;
        ll currSum = 0LL;
        for(int i=0;i<n;i++){
            currSum += (ll)nums[i];
            ll curr = (currSum/(i+1));
            if(currSum%(i+1)) curr++;
            maxi = max(maxi,curr);
        }
        return maxi;
        
    }
};
/*
3 7 1 6

3/1
10/2
11/3
17/4  
*/
  
    
     