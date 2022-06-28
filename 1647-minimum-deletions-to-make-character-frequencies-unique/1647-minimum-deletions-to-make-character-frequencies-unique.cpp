class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        
        vector<int>freq(26,0);
        
        for(char ch:s){
            freq[ch-'a']++;
        }
        
        vector<int>v;
        
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                v.push_back(freq[i]);
            }
        }
        
        
        sort(v.begin(),v.end());
        
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }cout<<"\n";
        
        int ans=0;
        
        n=v.size();
        
        if(n==1){
            return 0;
        }
        
        int idx=-1;
        
        for(int i=n-1;i>0;i--){
            
            if(v[i]>v[i-1]){
               // cout<<freq[i]<<" "<<freq[i-1]<<endl;
                continue;
            }
            
            else if(v[i]==v[i-1]){
                if(v[i-1]>0){
                    v[i-1]--;
                    ans++;
                }else{
                    idx=i-1;
                    break;
                }
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
        
       // cout<<ans<<"\n";
        
        for(int i=0;i<=idx;i++){
            ans+=v[i];
        }
        
        return ans;
        
    }
};