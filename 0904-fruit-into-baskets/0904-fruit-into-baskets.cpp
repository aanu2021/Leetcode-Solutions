class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>freq;
        int cnt = 0;
        int l = 0, r = 0;
        int maxLen = 0;
        while(r < n){
            if(freq[fruits[r]] == 0) cnt++;
            freq[fruits[r]]++;
            while(l <= r && cnt > 2){
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0) cnt--;
                if(freq[fruits[l]] == 0) freq.erase(fruits[l]);
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};