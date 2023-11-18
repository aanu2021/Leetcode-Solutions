class Solution {
public:
    
    typedef long long ll;
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int maxFreq = 0;
        vector<ll>prefix(n,0LL);
        prefix[0] = (ll)nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + (ll)nums[i];
        }
        for(int i=0;i<n;i++){
            int j = i;
            while(j<n && nums[j] == nums[i]){
                j++;
            }
            j--;
            int currFreq = 0;
            int low = 0, high = j;
            while(low <= high){
                int mid = (low + high)/2;
                ll currSum = prefix[j] - (mid - 1 >= 0 ? prefix[mid-1] : 0LL);
                ll reqOps = ((ll)(j-mid+1)*(ll)nums[j]) - currSum;
                if(reqOps <= k){
                    currFreq = (j-mid+1);
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            maxFreq = max(maxFreq, currFreq);
            i = j;
        }
        return maxFreq;
    }
};