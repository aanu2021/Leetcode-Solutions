class Solution {
public:
    
    vector<pair<int,int>>vec;
    
    vector<int>ans;
    
    void merge(int low,int mid,int high){
        
        int j=mid+1;
        
        for(int i=low;i<=mid;++i){
            
            while(j<=high && vec[j].first<vec[i].first){
                
                j++;
                
            }
            
            ans[vec[i].second]+=(j-mid-1);
            
        }
        
        sort(vec.begin()+low,vec.begin()+high+1);
        
    }
    
    void mergesort(int low,int high){
        
        if(low<high){
            
            int mid=(low+high)/2;
            
            mergesort(low,mid);
            
            mergesort(mid+1,high);
            
            merge(low,mid,high);
            
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        
        vec.resize(n); 
        
        ans.resize(n,0);
        
        for(int i=0;i<n;++i){
            
            vec[i]={nums[i],i};
            
        }
        
        mergesort(0,n-1);
        
        return ans;
        
    }
};