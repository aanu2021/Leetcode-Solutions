class Solution {
public:
    
    vector<int>ans;
    
    void merge(vector<pair<int,int>>&vec,int low,int mid,int high){
        
        vector<pair<int,int>>merged_arr;
        
        int leftpos=low,rightpos=mid+1;
        
        int right_less_left=0;
        
        while(leftpos<=mid && rightpos<=high){
            
            if(vec[leftpos].first > vec[rightpos].first){
                
                merged_arr.push_back(vec[rightpos]);
                
                rightpos++;
                
                right_less_left++;
                
            }
            
            else{
                
                merged_arr.push_back(vec[leftpos]);
                
                ans[vec[leftpos].second]+=right_less_left;
                
                leftpos++;
                
            }
            
        }
        
        while(leftpos<=mid){
            
            merged_arr.push_back(vec[leftpos]);
            
            ans[vec[leftpos].second]+=right_less_left;
            
            leftpos++;
            
        }
        
        while(rightpos<=high){
            
            merged_arr.push_back(vec[rightpos]);
            
            rightpos++;
            
        }
        
        int pos=low;
        
        for(auto m:merged_arr){
            
            vec[pos]=m;
            pos++;
            
        }
        
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