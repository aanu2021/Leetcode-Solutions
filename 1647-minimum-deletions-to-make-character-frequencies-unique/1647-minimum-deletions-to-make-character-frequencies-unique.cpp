class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        
        vector<int>freq(26,0);
        
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        vector<int>v;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                v.push_back(freq[i]);
            }
        }
        
        sort(v.begin(),v.end());
        
        n=v.size();
        
        int ans=0;
        
        int idx=-1;
        
        for(int i=n-1;i>0;i--){
            
            if(v[i]>v[i-1]){
                continue;
            }
            
            else if(v[i]==v[i-1]){
                
                if(v[i]==0){
                    idx=i-1;
                    break;
                }
                
                ans++;
                v[i-1]--;
                
            }
            
            else if(v[i]<v[i-1]){
                
                if(v[i]==0){
                    idx=i-1;
                    break;
                }
                
                ans+=(v[i-1]-(v[i]-1));
                
                v[i-1]=v[i]-1;
                
            }
            
        }
        
        for(int i=0;i<=idx;++i){
            ans+=v[i];
        }
        
        return ans;
        
    }
};