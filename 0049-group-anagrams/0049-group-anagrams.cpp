class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mapp;
        
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            string sort_str=str;
            sort(sort_str.begin(),sort_str.end());
            mapp[sort_str].push_back(str);
        }
        
        vector<vector<string>>ans;
        
        for(auto itr:mapp){
            
            vector<string>vec;
            
            for(auto it:itr.second){
                
                vec.push_back(it);
                
            }
            
            ans.push_back(vec);
            
        }
        
        return ans;
        
    }
};