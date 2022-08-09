class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.length();
        
        vector<vector<int>>index(26);
        
        for(int i=0;i<n;++i){
            
            index[s[i]-'a'].push_back(i);
            
        }
        
        int ans=0;
        
        for(string str:words){
            
            bool flag=true;
            
            int idx=-1;
            
            for(char ch:str){
                
                auto itr=upper_bound(index[ch-'a'].begin(),index[ch-'a'].end(),idx);
                
                if(itr==index[ch-'a'].end()){
                    
                    flag=false;
                    break;
                    
                }
                
                else{
                    
                    idx=*itr;
                    
                }
                
            }
            
            if(flag){
                ans++;
            }
            
        }
        
        return ans;
        
    }
};