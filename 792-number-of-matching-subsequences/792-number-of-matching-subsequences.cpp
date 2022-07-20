class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n=s.length();
        
        vector<vector<int>>vec(26);
        
        for(int i=0;i<n;++i){
            vec[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        
        string str="";
        
        for(int i=0;i<words.size();++i){
            
            str=words[i];
            
            bool flag=true;
            
            int idx=-1;
            
            for(char c:str){
                
                auto itr=upper_bound(vec[c-'a'].begin(),vec[c-'a'].end(),idx);
                
                if(itr==vec[c-'a'].end()){
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