class Solution {
public:
    
    struct comp{
        
      bool operator()(const pair<char,int>&x,const pair<char,int>&y){
          
          if(x.second==y.second){
              return x.first>y.first;
          }
          
          return x.second<y.second;
          
      }  
        
    };
    
    string get_result(string s,int d){

        int n=s.length();
        
        map<char,int>mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq(mp.begin(),mp.end());
        
        string res(s.length(),'_');
        
        while(!pq.empty()){
            
            auto curr=pq.top();
            pq.pop();
            
            int occurence=curr.second;
            char ch=curr.first;
            
            int p=-1;
            
            for(int i=0;i<n;i++){
                
                if(res[i]=='_'){
                    p=i;
                    break;
                }
                
            }
            
            if(p==-1){
                return "";
            }
            
            for(int i=0;i<occurence;i++){
                
                if(p>=n || res[p]!='_'){
                    return "";
                }
                
                res[p]=ch;
                p+=d;
                
            }
            
        }
        
        return res;
        
        
    }
    
    string reorganizeString(string s) {
        
        int n=s.length();
        
        char maxchar;
        int  maxfreq=0;
        
        vector<int>count(26,0);
        
        for(int i=0;i<n;i++){
            
            count[s[i]-'a']++;
            
            if(count[s[i]-'a']>maxfreq){
                maxfreq=count[s[i]-'a'];
                maxchar=s[i];
            }
            
        }
        
        if(maxfreq>(n+1)/2){
            return "";
        }
        
        string res(n,'_');
        
        int i=0;
        
        while(count[maxchar-'a']){
            
            res[i]=maxchar;
            
            i+=2;
            
            count[maxchar-'a']--;
            
        }
        
        
        for(int j=0;j<26;j++){
            
            while(count[j]>0){
                
                if(i>=n){
                    
                    i=1;
                }
                
                    res[i]=j+'a';
                    
                    i+=2;
                    
                    count[j]--;
                
            }
            
            
        }
            
          return res;  
        
    }
};