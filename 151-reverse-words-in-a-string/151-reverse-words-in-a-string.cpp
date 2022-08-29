class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        int i=0,j=0;
        
        int curridx=0;
        
        reverse(s.begin(),s.end());
        
        for(i=0;i<n;++i){
            
            if(s[i]==' '){
                continue;
            }
            
            j=i;
            
            if(curridx!=0){
                s[curridx++]=' ';
            }
            
            while(j<n && s[j]!=' '){
                s[curridx++]=s[j++];
            }
            
            reverse(s.begin()+curridx-j+i,s.begin()+curridx);
            
            i=j;
            i--;
            
        }
        
        s.erase(s.begin()+curridx,s.end());
        
        return s;
        
    }
};