class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        
        int ans = 0;
        
        int n = s.length();
        
        for(int i=0;i<n;++i){
            
            int j=i;
            
            int sum = 0 , maxi = 0;
            
            while(j<n && s[j]==s[i]){
                
                sum += neededTime[j];
                maxi = max(maxi,neededTime[j]);
                j++;
                
            }
            
            ans += (sum-maxi);
            
            i=j;
            i--;
            
        }
        
        return ans;
        
    }
};