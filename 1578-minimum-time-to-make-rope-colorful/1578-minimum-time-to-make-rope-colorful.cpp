class Solution {
public:
    int minCost(string s, vector<int>& T) {
        int n = s.length();
        int cost = 0;
        for(int i=0;i<n;i++){
            int j = i;
            int toti = 0;
            int maxi = T[i];
            while(j<n && s[i]==s[j]){
                toti += T[j]; maxi = max(maxi, T[j]); j++;
            }
            cost += (toti-maxi);
            i = j;
            i--;
        }
        return cost;
    }
};