class Solution {
public:
    
    bool canTake(vector<int>&piles,int n,int banana_per_hour,int maxHour){
        int currHour = 0;
        for(int i=0;i<n;i++){
            currHour += (piles[i]/banana_per_hour);
            if(piles[i]%banana_per_hour) currHour++;
            if(currHour > maxHour) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;
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

/*

4 11 20 23 30
    
1 + 1 + 1 + 1 + 2 = 6 <= 6
    
low  = 23
high = 22
mid = 23
    
ans = 23    

*/