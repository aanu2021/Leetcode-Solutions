class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        
//         arr: [5,3,3,3,5,6,2]
        
//         pre: [0,1,2,3,0,0,1]
        
//         suf: [0,4,3,2,1,0,0]
        
        
         int n=nums.size();
        
         vector<int>prefix(n,0);
        
         vector<int>suffix(n,0);
        
         int cnt=0;
        
         for(int i=1;i<n;++i){
             
             if(nums[i]<=nums[i-1]){
                 cnt++;
             }else{
                 cnt=0;
             }
             
             prefix[i]=cnt;
             
         }
        
        cnt=0;
        
        for(int i=n-2;i>=0;--i){
            
            if(nums[i]<=nums[i+1]){
                cnt++;
            }else{
                cnt=0;
            }
            
            suffix[i]=cnt;
            
        }
        
        vector<int>ans;
        
        for(int i=0;i<n;++i){
            if(prefix[i]>=time && suffix[i]>=time){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};