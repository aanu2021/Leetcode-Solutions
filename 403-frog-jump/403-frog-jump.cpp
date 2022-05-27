class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        int n=stones.size();
        
        map<int,set<int>>mp;
        
        mp[1].insert(1);
        
        for(int i=1;i<n-1;i++){
            
            for(int jump:mp[stones[i]]){
                
                mp[stones[i]+jump+1].insert(jump+1);
                mp[stones[i]+jump].insert(jump);
                mp[stones[i]+jump-1].insert(jump-1);
                
            }
            
        }
        
        return !mp[stones[n-1]].empty();
        
    }
};