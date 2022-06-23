class Solution {
public:
    
    bool static comp(const string&s1,const string&s2){
        return s1.length() > s2.length();
    }
    
    // "em" "emit"
    
    bool isMatch(string s1,string s2){
        
        int m=s1.length();
        int n=s2.length();
        
        int k=0;
        
        for(int i=0;i<m;i++){
            if(s1[i]==s2[i]){
                k++;
            }
            else{
                return false;
            }
        }
        
        return true;
        
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
        
        sort(words.begin(),words.end(),comp);
        
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<words[i]<<" ";
        // }
        
        set<string>S;
        
        int ans=0;
        
        S.insert(words[0]);
        
        ans+=words[0].length();
        
        ans++;
        
        string curr="";
        
        for(int i=1;i<n;i++){
            
            auto itr=S.lower_bound(words[i]);
            
            bool flag=false;
            
            if(itr!=S.end()){
                
               // cout<<(*itr)<<endl;
                
                curr=*itr;
                
                int len=words[i].length();
                
                if(curr.substr(0,len)==words[i]){
                    flag=true;
                }
                
                // if(isMatch((*itr),words[i])==true){
                //     flag=true;
                // }
                
            }
            
            if(flag==false){
                
                ans+=words[i].length();
                ans++;
                
                S.insert(words[i]);
                
            }
            
           // cout<<ans<<endl;
            
        }
        
        return ans;
        
    }
};