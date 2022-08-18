class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        vector<int>v;
        
        for(auto itr:mp){
            v.push_back(itr.second);
        }
        
        sort(v.rbegin(),v.rend());
        
        int k=(n/2);
        
        int ans=0;
        
        for(int i=0;i<v.size() && k>0;++i){
            
            k-=v[i];
            ans++;
            
        }
        
        return ans;
        
    }
};