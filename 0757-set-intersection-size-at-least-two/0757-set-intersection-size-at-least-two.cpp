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
        int highestVal = intervals[0][1];
        int secondHighestVal = intervals[0][1] - 1;
        
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start > highestVal){
                answer += 2;
                highestVal = intervals[i][1];
                secondHighestVal = intervals[i][1] - 1;
            }
            else if(start > secondHighestVal){
                answer += 1;
                secondHighestVal = highestVal;
                highestVal = intervals[i][1];
            }
        }
        
        return answer;
        
    }
};

/*

[1,3] [3,7] [5,7] [7,8]

answer = 3
    
highestVal = 7
secondHighestVal = 3
    
*/    
    