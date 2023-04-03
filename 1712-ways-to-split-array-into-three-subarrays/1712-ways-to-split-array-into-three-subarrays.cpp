class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1];
            prefix[i] += nums[i];
        }
        ll ways = 0LL;
        for(int i=1;i<n-1;i++){
            int leftSum = prefix[i-1];
            int lidx = -1, ridx = -1;
            int low = i , high = n-2;
            lidx = lower_bound(prefix.begin()+i,prefix.begin()+n-1,2*leftSum) - prefix.begin();
            if(lidx >= n-1) lidx = -1;
            if(lidx != -1){
                low = lidx , high = n-2;
                while(low <= high){
                    int mid = (low + high)/2;
                    int midSum = prefix[mid] - prefix[i-1];
                    int rightSum = prefix[n-1] - prefix[mid];
                    if(midSum >= leftSum && rightSum >= midSum){
                        ridx = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }    
            }
            
            // cout<<lidx<<" "<<ridx<<"\n";
            if(lidx == -1 || ridx == -1) continue;
            ways += (ll)(ridx-lidx+1);
            ways %= M;
        }
        return ways;
    }
};