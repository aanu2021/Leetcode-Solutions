class Solution {
public:
    
    vector<int>ans;
    
    void merge(vector<pair<int,int>>&vec,int low,int mid,int high){
        
        int j=mid+1;
        
        for(int i=low;i<=mid;++i){
            
            while(j<=high && vec[i].first>vec[j].first){
                j++;
            }
            
            ans[vec[i].second]+=(j-mid-1);
            
        }
        
        sort(vec.begin()+low,vec.begin()+high+1);
        
        return;
        
    }
    
    void mergesort(vector<pair<int,int>>&vec,int low,int high){
        
        if(low<high){
            
            int mid=(low+high)/2;
            
            mergesort(vec,low,mid);
            
            mergesort(vec,mid+1,high);
            
            merge(vec,low,mid,high);
            
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<pair<int,int>>vec(n);
        
        ans.resize(n,0);
        
        for(int i=0;i<n;i++){
            vec[i]={nums[i],i};
        }
        
        mergesort(vec,0,n-1);
        
        return ans;
        
    }
};