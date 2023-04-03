class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1];
            prefix[i] += nums[i];
        }
        ll answer = 0LL;
        for(int i=1;i<n-1;i++){
            int leftSum = prefix[i-1];
            int lidx = lower_bound(prefix.begin()+i,prefix.end(),2*leftSum) - prefix.begin();
            if(lidx >= n-1) lidx = -1;
            int ridx = -1;
            if(lidx != -1){
                int low = lidx , high = n-2;
                while(low <= high){
                    int mid = (low + high)/2;
                    int midSum = prefix[mid] - prefix[i-1];
                    int rightSum = prefix[n-1] - prefix[mid];
                    if(leftSum <= midSum && midSum <= rightSum){
                        ridx = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
            if(lidx != -1 && ridx != -1){
                answer += (ll)(ridx-lidx+1);
                answer %= M;
            }
        }
        return answer;
    }
};