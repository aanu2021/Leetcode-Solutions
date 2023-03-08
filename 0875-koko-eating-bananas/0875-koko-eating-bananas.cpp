class Solution {
public:
    
    bool canTake(vector<int>&piles,int n,int bph,int maxHour){
        int totHour = 0;
        for(int i=0;i<n;i++){
            totHour += (piles[i]/bph);
            if(piles[i]%bph) totHour++;
            if(totHour > maxHour) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1,high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canTake(piles,n,mid,h)){
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