class Solution {
public:
    
    bool isPossible(vector<int>&dist,int mid,double hour){
        int n = dist.size();
        int currSum = 0;
        for(int i=0;i<n-1;i++){
            currSum += (dist[i]/mid);
            if(dist[i]%mid) currSum++;
            if(currSum*1.0 > hour){
                return false; 
            }
        }
        double current = (double)currSum;
        current += (dist[n-1]*1.0)/mid;
        return current <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 10000000;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(dist,mid,hour)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};