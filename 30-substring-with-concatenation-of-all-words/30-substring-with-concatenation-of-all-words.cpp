class Solution {
public:
    
    bool isConsistAll(string &s,int idx,int Len,int ind_len,unordered_map<string,int>&mp){
        
//         for(auto itr:mp){
            
//             cout<<itr.first<<" "<<itr.second<<"\n";
            
//         }
        
        string str="";
        
        int cnt=0;
        
        for(int i=idx;i<idx+Len;++i){
            
            str+=s[i];
            
            cnt++;
            
            // cout<<str<<" "<<cnt<<"\n";
            
            if(cnt==ind_len){
                
                cnt=0;
                
                if(mp.find(str)==mp.end()){
 
                    return false;
                    
                }
                
                else{
                    
                    mp[str]--;
                    
                }
                
                str="";
                
            }
            
        }
        
        
        for(auto itr:mp){
            
            if(itr.second!=0){
                return false;
            }
            
        }
        
        return true;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n=s.length();
        
        int len=0;
        
        int each_len=0;
        
        for(int i=0;i<words.size();++i){
            len+=words[i].length();
            each_len=words[0].length();
        }
        
      //  cout<<len<<"\n";
        
        
        unordered_map<string,int>mp;
        
        vector<int>ans;
        
        for(int i=0;i<=n-len;++i){
            
            for(string str:words){
                mp[str]++;
            }
            
            bool curr_dec=isConsistAll(s,i,len,each_len,mp);
            
            if(curr_dec){
                
                ans.push_back(i);
                
            }
            
            mp.clear();
            
        }
        
        return ans;
        
    }
};