class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = n;
        int i = 0;
        for(i=1;i<n;){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                ans += peak;
                i++;
                if(i==n) return ans;
            }
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                ans += valley;
                i++;
            }
            ans -= min(peak,valley);
        }
        return ans;
    }
};

  