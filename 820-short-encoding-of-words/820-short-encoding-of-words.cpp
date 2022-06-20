class Solution {
public:
    
    bool static comp(string &s1,string &s2){
        return s1.length() > s2.length();
    }
    
    bool isMatch(string s1,string s2){
        
        int m=s1.length();
        int n=s2.length();
        
        int k=0;
        
        for(int i=0;i<n;++i){
            if(s2[i]==s1[k]){
                k++;
            }else{
                break;
            }
        }
        
        return k==m;
        
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
      
        sort(words.begin(),words.end(),comp);
        
        set<string>S;
      
        for(int i=0;i<n;i++){
            
            reverse(words[i].begin(),words[i].end());
            
            // cout<<words[i]<<" ";
            
        }// cout<<endl;
        
        int ans=1+words[0].length();
        
        S.insert(words[0]);
        
        for(int i=1;i<n;i++){
            
            auto itr=S.lower_bound(words[i]);
            
            bool flag=false;
            
            if(itr!=S.end()){
                
               // cout<<"as,ghd";
                
                if(isMatch(words[i],*itr)==true){
                    flag=true;
                }else{
                    flag=false;
                }
                
            }
            
           // cout<<flag<<" ";
            
            if(flag){
                
                
            }
            
            else{
                
                ans+=words[i].length();
                ans++;
                
                S.insert(words[i]);
                
            }
            
        }
 
        return ans;
        
    }
};