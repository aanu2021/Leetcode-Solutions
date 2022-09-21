class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int q=queries.size();
        
        vector<int>ans(q,0);
        
        int even_sum=0;
        
        for(int i:nums){
            if(i%2==0){
                even_sum+=i;
            }
        }
        
        for(int i=0;i<q;++i){
            
            int idx=queries[i][1];
            int val=queries[i][0];
            
            if(nums[idx]%2==0){
                even_sum-=nums[idx];
            }
            
            nums[idx]+=val;
            
            if(nums[idx]%2==0){
                even_sum+=nums[idx];
            }
            
            ans[i]=even_sum;
            
        }
        
        return ans;
        
    }
};


//1 2 3 4
    
    
