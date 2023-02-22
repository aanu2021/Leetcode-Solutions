class Solution {
public:
    
    bool CanDo(vector<int>&weights,int n,int capacity,int days){
        int currDays = 1;
        int currSum = 0;
        for(int i=0;i<n;i++){
            if(weights[i] > capacity) return false;
            if(currSum + weights[i] <= capacity){
                currSum += weights[i];
            }
            else{
                currDays++;
                currSum = weights[i];
            }
        }
        return currDays <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0 , high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(CanDo(weights,n,mid,days)){
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