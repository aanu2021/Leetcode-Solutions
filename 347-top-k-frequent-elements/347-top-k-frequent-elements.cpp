class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int>freq;
        
        for(int ele:nums){
            freq[ele]++;
        }
        
        vector<int>freq_arr(n+1,0);
        
        unordered_map<int,vector<int>>freq_to_ele;
        
        for(auto itr:freq){
            
            freq_to_ele[itr.second].push_back(itr.first);
            
            freq_arr[itr.second]++;
            
        }
        
        vector<int>ans;
        
        for(int i=n;i>=1 && k>0;i--){
            
            while(freq_arr[i] && k){
                
                ans.push_back(freq_to_ele[i].back());
                
                freq_to_ele[i].pop_back();
                
                k--;
                
                freq_arr[i]--;
                
            }
            
        }
        
        return ans;
        
    }
};