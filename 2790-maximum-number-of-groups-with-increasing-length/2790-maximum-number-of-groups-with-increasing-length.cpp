class Solution {
public:
    
    typedef long long ll;
    
    bool isPossible(vector<int>A,int n,int mid){
        ll sum = 0LL;
        int req = mid;
        for(int i=0;i<n;i++){
            if(A[i] >= req){
                A[i] -= req;
                if(A[i] >= 0 && sum > 0){
                    sum -= min(sum, (ll)A[i]);
                }
            }
            else{
                sum += (ll)(req - A[i]);
            }
            if(req > 0){
                req--;
            }
        }
        return sum <= 0;
    }
    
    int maxIncreasingGroups(vector<int>& A) {
        int n = A.size();
        sort(A.rbegin(),A.rend());
        int low = 1, high = n;
        int ans = 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(A,n,mid)){
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