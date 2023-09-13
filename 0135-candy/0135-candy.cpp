class Solution {
public:
    
    // O(N) Time 
    // O(N) Space
    
    /*
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        int answer = 0;
        for(int i=0;i<n;i++){
            answer += max(left[i],right[i]);
        }
        return answer;
    }
    */
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int answer = n;
        int i = 0;
        for(i=1;i<n;){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            int peak = 0;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                answer += peak;
                i++;
                if(i==n) return answer;
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