class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int sum = 0;
        int maxLen = 0;
        
        unordered_map<int,int>mp;
        
        mp[0] = -1;
        
        for(int i=0;i<n;i++){
            
            sum += nums[i];
            
            int rem = (sum%k);
            
            sum = sum%k;
            
            if(mp.find(rem)!=mp.end()){
                
                maxLen = max(maxLen,i-mp[rem]);
                
            }
            
            else{
                
                mp[rem] = i;
                
            }
            
        }
        
        if(maxLen>=2) return true;
        else return false;
        
    }
};