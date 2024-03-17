class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            return {newInterval};
        }
        // Base Cases...
        if(intervals[n-1][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval[1] < intervals[0][0]){
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        int L = newInterval[0];
        int R = newInterval[1];
        int index = n;
        for(int i=0;i<n;i++){
            if(intervals[i][0] > newInterval[1]){
                index = i;
                break;
            }
        }
        // cout<<index<<"\n";
        // index -> position where we should place newInterval
        int leftIndex = -1;
        int rightIndex = n;
        for(int i=index-1;i>=0;i--){
            if(L <= intervals[i][0]){
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
                continue;
            }
            else if(L >= intervals[i][0] && L <= intervals[i][1]){
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
                leftIndex = i-1;
                break;
            }
            else{
                leftIndex = i;
                break;
            }
        }
        // cout<<L<<" "<<R<<"\n";
        // cout<<leftIndex<<"\n";
        vector<vector<int>>answer;
        for(int i=0;i<=leftIndex;i++){
            answer.push_back(intervals[i]);
        }
        answer.push_back({L,R});
        for(int i=index;i<n;i++){
            answer.push_back(intervals[i]);
        }
        return answer;
    }
};

// 0 1 2 3 x 4 5 6
                 
    
