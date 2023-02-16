class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        int m = heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int>left(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        int i=0, j=0;
        while(i<n && j<m){
            if(houses[i] <= heaters[j]){
                right[i] = min(right[i],heaters[j]-houses[i]);
                i++;
            }
            else{
                j++;
            }
        }
        i=n-1, j=m-1;
        while(i>=0 && j>=0){
            if(houses[i] >= heaters[j]){
                left[i] = min(left[i],houses[i]-heaters[j]);
                i--;
            }
            else{
                j--;
            }
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = min(left[i],right[i]);
        }
        return *max_element(ans.begin(),ans.end());
    }
};