class Solution {
public:
    
    int func(vector<int>&arr){
        
        int n=arr.size();
        
        vector<int>tails;
        
        tails.push_back(arr[0]);
        
        for(int i=1;i<n;++i){
            
            if(tails.back()<=arr[i]){
                tails.push_back(arr[i]);
            }
            
            else{
                int idx=upper_bound(tails.begin(),tails.end(),arr[i])-tails.begin();
                tails[idx]=arr[i];
            }
            
        }
        
        return tails.size();
        
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        int ans=0;
        
        for(int i=0;i<k;++i){
            
            vector<int>v;
            
            for(int j=i;j<n;j+=k){
                
                v.push_back(arr[j]);
                
            }
            
            int sz=v.size();
            
            int lnds=func(v);
            
            ans+=(sz-lnds);
            
        }
        
        return ans;
        
    }
};