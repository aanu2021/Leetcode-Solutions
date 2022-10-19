class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<pair<int,int>>vec;
        
        unordered_map<int,int>mp;
        
        for(int i:nums){
            mp[i]++;
        }
        
        for(auto itr:mp){
            vec.push_back({-itr.second,itr.first});
        }
        
        sort(vec.begin(),vec.end());
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            
            ans.push_back(vec[i].second);
            
        }
        
        return ans;
        
    }
};