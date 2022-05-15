class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
      map<int,int>mp;
        
      int n=intervals.size();
        
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=intervals[i][1];
        }
        
        int left=newInterval[0];
        int right=newInterval[1];
        
        auto itr=mp.upper_bound(left);
        
        if(itr!=mp.begin()){
            
            auto p=prev(itr);
            
            if(p->second>=left){
                
                left=p->first;
                right=max(right,p->second);
                
                mp.erase(p);
                
            }
            
        }
        
        
        for(;itr!=mp.end() && itr->first<=right ; mp.erase(itr++)){
            
            right=max(right,itr->second);
            
        }
        
        mp[left]=right;
        
        vector<vector<int>>result;
        
        for(auto it:mp){
            result.push_back({it.first,it.second});
        }
        
        return result;
        
    }
};