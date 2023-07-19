class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        if(x[1] == y[1]){
            return x[0] > y[0];
        }
        return x[1] < y[1];
    }
    
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        
        int answer = 2;
        int highest = intervals[0][1];
        int secondHighest = intervals[0][1] - 1;
        
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start > highest){
                answer += 2;
                highest = end;
                secondHighest = end - 1;
            }
            else if(start > secondHighest){
                answer += 1;
                secondHighest = highest;
                highest = end;
            }
        }
        
        return answer;
        
    }
};


/*

[[1,3],[3,7],[5,7],[7,8]]


*/