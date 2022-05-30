class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n=s.length();
        
        map<char,vector<int>>mp;
        
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        
        int ans=0;
        
        for(char ch1='a';ch1<='z';ch1++){
            
            for(char ch2='a';ch2<='z';ch2++){
                
                int extreme_size=mp[ch1].size();
                int middle_size=mp[ch2].size();
                
                if(ch1==ch2 && extreme_size>=3){
                    
                    ans++;
                    continue;
                    
                }
                
                else if(ch1!=ch2 && extreme_size>=2 && middle_size>=1){
                    
int idx=upper_bound(mp[ch2].begin(),mp[ch2].end(),mp[ch1][0])-mp[ch2].begin();
                    
                    if(idx==middle_size){
                        
                        continue;
                        
                    }
                    
                    else{
                        
                        int currval=mp[ch2][idx];
                        
                        if(currval>mp[ch1][0] && currval<mp[ch1].back()){
                            ans++;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};