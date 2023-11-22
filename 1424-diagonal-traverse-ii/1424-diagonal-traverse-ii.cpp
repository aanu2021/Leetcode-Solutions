class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        map<int,vector<pair<int,int>>>mp;
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums[i].size()-1;j>=0;j--){
                mp[i+j].push_back({i,j});
            }
        }
        
        vector<int>result;
        
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            
            for(int k=0;k<itr->second.size();k++){
                
                result.push_back(nums[itr->second[k].first][itr->second[k].second]);
                
            }
            
        }
        
        return result;
        
    }
};