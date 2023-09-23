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
    
    // O(N) Time
    // O(1) Space
    
    /*
    
    1. Peak calculation is important.
    2. peak = max(left_peak,right_valley)
    3. valley elements have exactly 1 candy
    4. When two equal elements are there, both resets to 1
    5. In our algorithm peak and valley values are calculated twice,        therefore we need to subtract the minimum among them.
    
    */
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int answer = n;
        int i = 1;
        for(;i<n;){
            if(ratings[i]==ratings[i-1]){
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