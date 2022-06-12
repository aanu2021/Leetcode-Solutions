class Solution {
public:
    bool matchReplacement(string s, string t, vector<vector<char>>& mappings) {
        
        int n=s.length();
        int m=t.length();
        
        unordered_map<char,unordered_map<char,int>>mp;
        
        for(int i=0;i<mappings.size();i++){
            mp[mappings[i][0]][mappings[i][1]]++;
        }
        
        bool flag=false;
        
        for(int i=0;i<=n-m;i++){
            
            flag=true;
            
            for(int j=0;j<m;j++){
                
                if(t[j]==s[i+j]){
                    continue;
                }
                
                else{
                    
                    if(mp[t[j]][s[i+j]]>0){
                        continue;
                    }else{
                        flag=false;
                        break;
                    }
                    
                }
                
            }
            
            if(flag==true){
                break;
            }
            
        }
        
        return flag;
        
    }
};