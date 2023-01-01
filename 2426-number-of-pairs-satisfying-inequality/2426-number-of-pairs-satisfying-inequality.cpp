class Solution {
public:
    
    typedef long long ll;
    
    ll merge(vector<int>&d,int low,int mid,int high,int diff){
        
        ll ans = 0LL;
        
        int j = high;
        
        for(int i=mid;i>=low;i--){
            while(j>mid && d[i] <= d[j]+diff){
                j--;
            }
            ans += (high-j);
        }
        
        sort(d.begin()+low,d.begin()+high+1);
        return ans;
        
    }
    
    ll mergesort(vector<int>&d,int low,int high,int diff){
        
        ll ans = 0LL;
        
        if(low < high){
            
            int mid = (low + high) / 2;
            
            ans += mergesort(d,low,mid,diff);
            ans += mergesort(d,mid+1,high,diff);
            ans += merge(d,low,mid,high,diff);
            
        }
        
        return ans;
        
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int>d(n);
        for(int i=0;i<n;i++){
            d[i] = nums1[i] - nums2[i];
        }
        ll ans = mergesort(d,0,n-1,diff);
        return ans;
    }
};

/*

a[i] - a[j] <= b[i] - b[j] + diff
a[i] - b[i] <= a[j] - b[j] + diff
    X[i]    <=     X[j]    + diff ..... (1)
    
    i < j
    
    figure out the number of pairs (i,j) satisfying the condition 1

    

*/