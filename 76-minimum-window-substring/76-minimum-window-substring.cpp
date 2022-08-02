class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.length();
        int m=t.length();
        
        map<char,int>mp;
        
        int count=0;
        
        for(int i=0;i<m;++i){
            
            if(mp[t[i]]==0){
                count++;
            }
            
            mp[t[i]]++;
            
        }
        
        int l=0,r=0;
        
        int startidx=-1,minLen=n+1;
        
        while(r<n){
            
           mp[s[r]]--;
            
           if(mp[s[r]]==0){
               count--;
           } 
            
           while(l<=r && count==0){
               
               int currLen=(r-l+1);
               
               if(currLen<minLen){
                   
                   minLen=currLen;
                   startidx=l;
                   
               }
               
               mp[s[l]]++;
               
               if(mp[s[l]]>0){
                   
                   count++;
                   
               }
               
               l++;
               
           }
            
           r++; 
            
        }
        
        if(minLen==n+1){
            return "";
        }else{
            return s.substr(startidx,minLen);
        }
        
    }
};