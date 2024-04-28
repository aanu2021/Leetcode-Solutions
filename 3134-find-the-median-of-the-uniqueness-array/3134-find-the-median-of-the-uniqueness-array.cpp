class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>&nums, int n, int mid, ll target){
        int l = 0, r = 0, count = 0;
        unordered_map<int,int>freq;
        ll currSum = 0LL;
        while(r < n){
            if(freq[nums[r]] == 0) count++;
            freq[nums[r]]++;
            while(l <= r && count > mid){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) count--;
                l++;
            }
            currSum += (ll)(r-l+1);
            r++;
        }
        return currSum >= target;
    }
    
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        ll total = (((ll)n*(ll)(n+1))/2LL);
        ll target = (total + 1)/2LL;
        int low = 1, high = n;
        int answer = high;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(nums, n, mid, target)){
                answer = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return answer;
    }
};

/*

3 4 3 4 5
     
    
    1 + 2 + 3 + 4 + 2 
    
    total = (n*(n+1))/2
    target = (total + 1)/2
    
    low = 2
    high = 1
    mid = 2 xxx
    
    currSum = 12 >= target
    answer = mid = 2
    
*/    