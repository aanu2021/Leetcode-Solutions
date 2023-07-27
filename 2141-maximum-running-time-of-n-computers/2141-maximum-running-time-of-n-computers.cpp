class Solution {
public:
    
    typedef long long ll;
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll low = 0LL, high = 1e14;
        ll ans = 0LL;
        
        while(low <= high){
            ll mid = (low + high)/2;
            ll currSum = 0LL;
            ll reqSum = mid*(ll)n;
            bool flag = false;
            for(int &ele : batteries){
                currSum += min((ll)ele, mid);
                if(currSum >= reqSum){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
};