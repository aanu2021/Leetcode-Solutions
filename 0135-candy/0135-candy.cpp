class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int answer = n;
        int i = 1;
        for(;i<n;){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                answer += peak;
                i++;
            }
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                answer += valley;
                i++;
            }
            answer -= min(peak, valley);
        }
        return answer;
    }
};