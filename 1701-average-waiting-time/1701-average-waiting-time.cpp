class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        int n = arr.size();
        double answer = 0.0;
        int endTime = arr[0][0];
        for(int i=0;i<n;i++){
            endTime = max(endTime, arr[i][0]);
            endTime += arr[i][1];
            answer += (double)(endTime - arr[i][0]);
        }
        answer = answer / (1.0 * n);
        return answer;
    }
};

// 11 
    
// 3 - 1 = 2    
// 8 - 2 = 6    
// 11 - 4 = 7    