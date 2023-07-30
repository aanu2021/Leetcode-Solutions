class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int dist = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        dist = mp.size();
        int answer = 0;
        int l = 0,r = 0;
        unordered_map<int,int>freq;
        while(r<n){
            freq[nums[r]]++;
            while(freq.size() == dist){
                answer += (n-r);
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            }
            r++;
        }
        return answer;
    }
};

   
    