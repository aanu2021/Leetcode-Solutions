class Solution {
public:
    
    string str_sort(string &str){
        
        int n = str.length();
        
        vector<int>count(26,0);
        
        for(char ch:str){
            count[ch-'a']++;
        }
        
        string res="";
        
        for(int i=0;i<26;i++){
            res+=string(count[i],i+'a');
        }
        
        return res;
        
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>mapp;
        
        // for(int i=0;i<strs.size();i++){
        //     string str=strs[i];
        //     string sort_str=str;
        //     sort(sort_str.begin(),sort_str.end());
        //     mapp[sort_str].push_back(str);
        // }
        
        for(string &str:strs){
            mapp[str_sort(str)].push_back(str);
        }
        
        vector<vector<string>>ans;
        
        for(auto itr:mapp){
            
            vector<string>vec;
            
            for(auto &it:itr.second){
                
                vec.push_back(it);
                
            }
            
            ans.push_back(vec);
            
        }
        
        return ans;
        
    }
};