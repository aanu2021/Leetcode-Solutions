class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        for(int i:nums){
            mp[i]++;
        }
        
        unordered_map<int,vector<int>>freq;
        
        vector<int>freq_arr(n+1,0);
        
        for(auto itr:mp){
            freq[itr.second].push_back(itr.first);
            freq_arr[itr.second]++;
        }
        
        vector<int>ans;
        
        for(int i=n;i>=1;i--){
            
            while(k>0 && freq_arr[i]>0){
                
                ans.push_back(freq[i].back());
                freq[i].pop_back();
                
                freq_arr[i]--;
                k--;
                
            }
            
        }
        
        return ans;
        
    }
};