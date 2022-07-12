class Solution {
public:
    
    typedef long long ll;
    
    vector<pair<ll,ll>>vec;
    
    void merge1(vector<ll>&ans,ll low,ll mid,ll high){
        
        ll j=mid+1;
        
        for(ll i=low;i<=mid;++i){
            
            while(j<=high && vec[i].first>=vec[j].first){
                
                j++;
                
            }
            
            ans[vec[i].second]+=(high-j+1);
            
        }
        
        sort(vec.begin()+low,vec.begin()+high+1);
        
    }
    
    void mergesort1(vector<ll>&ans,ll low,ll high){
        
        if(low<high){
            
            ll mid=(low+high)/2;
            
            mergesort1(ans,low,mid);
            
            mergesort1(ans,mid+1,high);
            
            merge1(ans,low,mid,high);
            
        }
        
    }
    
    void merge2(vector<ll>&ans,ll low,ll mid,ll high){
        
        ll j=mid+1;
        
        for(ll i=low;i<=mid;++i){
            
            while(j<=high && vec[i].first>vec[j].first){
                
                j++;
                
            }
            
            ans[vec[i].second]+=(j-mid-1);
            
        }
        
        sort(vec.begin()+low,vec.begin()+high+1);
        
    }
    
    void mergesort2(vector<ll>&ans,ll low,ll high){
        
        if(low<high){
            
            ll mid=(low+high)/2;
            
            mergesort2(ans,low,mid);
            
            mergesort2(ans,mid+1,high);
            
            merge2(ans,low,mid,high);
            
        }
        
    }
    
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        ll n=(ll)nums1.size();
        
        vec.resize(n);
        
        map<ll,ll>mp;
        
        for(ll i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        
        
        for(ll i=0;i<n;i++){
            nums1[i]=mp[nums1[i]];
        }
        
        
        for(ll i=0;i<n;i++){
            
            vec[i]={nums1[i],i};
            
        }
        
        
        vector<ll>left(n,0LL);
        
        vector<ll>right(n,0LL);
        
        mergesort1(right,0,n-1);
        
        reverse(nums1.begin(),nums1.end());
        
        for(ll i=0;i<n;i++){
            
            vec[i]={nums1[i],i};
            
        }
        
        mergesort2(left,0,n-1);
        
        reverse(left.begin(),left.end());
        
        ll value=0LL;
        
        for(ll i=1;i<n-1;++i){
            
            value+=(left[i]*right[i]);
            
        }
        
        return value;
        
    }
};