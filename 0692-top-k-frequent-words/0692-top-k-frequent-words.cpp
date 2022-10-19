class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        vector<pair<int,string>>vec;
        
        for(auto itr:mp){
            vec.push_back({-itr.second,itr.first});
        }
        
        sort(vec.begin(),vec.end());
        
        vector<string>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        
        return ans;
        
    }
};