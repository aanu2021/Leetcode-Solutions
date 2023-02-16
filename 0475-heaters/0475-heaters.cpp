class Solution {
public:
    
    bool isPossible(vector<int>&houses,vector<int>&heaters,int radius){
        int n = houses.size();
        int m = heaters.size();
        int i = 0, j = 0;
        while(i<n){
            if(j==m) return false;
            int minLeft = heaters[j] - radius;
            int maxRight = heaters[j] + radius;
            if(houses[i] < minLeft || houses[i] > maxRight){
                j++;
            }
            else{
                i++;
            }
        }
        return true;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low = 0;
        int high = 0;
        for(int ele : houses){
            high = max(high,ele);
        }
        for(int ele : heaters){
            high = max(high,ele);
        }
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(houses,heaters,mid)){
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