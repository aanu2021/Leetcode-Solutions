class Solution {
public:
    
    typedef long long ll;
    const ll M = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>ps(n, -1);
        vector<int>ns(n, n);
        stack<int>S;
        for(int i=0;i<n;i++){
            while(!S.empty() && arr[S.top()] > arr[i]){
                S.pop();
            }
            if(!S.empty()) ps[i] = S.top();
            S.push(i);
        }
        while(!S.empty()) S.pop();
        for(int i=n-1;i>=0;i--){
            while(!S.empty() && arr[S.top()] >= arr[i]){
                S.pop();
            }
            if(!S.empty()) ns[i] = S.top();
            S.push(i);
        }
        ll total = 0LL;
        for(int i=0;i<n;i++){
            ll left = (ll)(i-ps[i]);
            ll right = (ll)(ns[i]-i);
            total += (left*right*(ll)arr[i]);
            total %= M;
        }
        return total;
    }
};


     
     
     
     
     
    