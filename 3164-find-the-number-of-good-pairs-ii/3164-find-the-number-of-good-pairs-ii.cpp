class Solution {
public:
    
    typedef long long ll;
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int M = *max_element(nums1.begin(),nums1.end());
        vector<int>freq(M+1, 0);
        unordered_map<int,int>mp;
        for(int &ele : nums2){
            mp[ele*k]++;
        }
        for(int i=1;i<=M;i++){
            if(mp[i] == 0) continue;
            for(int j=i;j<=M;j+=i){
                freq[j] += mp[i];
            }
        }
        ll answer = 0LL;
        for(int &ele : nums1){
            answer += (ll)freq[ele];
        }
        return answer;
    }
};