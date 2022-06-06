class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        vector<int>v;
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        v.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(v.back()!=nums[i]){
                v.push_back(nums[i]);
            }
        }
        
        int m=v.size();
        
        int ans=n+1;
        
        for(int i=0;i<m;i++){
            
            int j=upper_bound(v.begin()+i,v.end(),v[i]+n-1)-v.begin();
            
            ans=min(ans,n-(j-i));
            
        }
        
        return ans;
        
    }
};