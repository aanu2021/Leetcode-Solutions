class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        double need = (n*1.0)/4;
        for(int i=0;i<n;i++){
            int j = i;
            int cnt = 0;
            while(j<n && arr[j]==arr[i]){
                cnt++; j++;
            }
            if(cnt > need) return arr[i];
            i = j;
            i--;
        }
        return -1;
    }
};