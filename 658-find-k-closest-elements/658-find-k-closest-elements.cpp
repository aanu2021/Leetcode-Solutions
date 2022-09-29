class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        
        int n=nums.size();
        
        int idx=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
        
        int mid = idx;
        
        int i,j;
        
        if(mid==0){
            
            i=mid;
            j=mid+1;
            
        }
        
        else{
            
            if(mid+1<n){
                
                if(abs(nums[mid-1]-x)<=abs(nums[mid+1]-x)){
                    
                    i=mid-1;
                    j=mid;
                    
                }
                
                else{
                    
                    i=mid;
                    j=mid+1;
                    
                }
                
            }
            
            else{
                
                i=mid-1;
                j=mid;
                
            }
            
        }
        
        
        vector<int>result;
        
        while(i>=0 && j<n && k>0){
            
            if(abs(nums[i]-x)<=abs(nums[j]-x)){
                
                result.push_back(nums[i]);
                
                i--;
                
            }
            
            else{
                
                result.push_back(nums[j]);
                
                j++;
                
            }
            
            k--;
            
        }
        
        while(i>=0 && k>0){
            
            result.push_back(nums[i]);
            
            i--;
            
            k--;
            
        }
        
        while(j<n && k>0){
            
            result.push_back(nums[j]);
            
            j++;
            
            k--;
            
        }
        
        sort(result.begin(),result.end());
        
        return result;
        
    }
};