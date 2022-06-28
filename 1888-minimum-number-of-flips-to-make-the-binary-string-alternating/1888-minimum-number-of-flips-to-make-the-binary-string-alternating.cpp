class Solution {
public:
    int minFlips(string s) {
        
        int n=s.length();
        
        int m=2*n;
        
        string temp=s;
        
        s+=s;
        
        int ans=n;
        
        string a="",b="";
        
        for(int i=0;i<m;i++){
            if(i%2==0){
                a+="1";
            }else{
                a+="0";
            }
        }
        
        for(int i=0;i<m;i++){
            if(i%2==0){
                b+="0";
            }else{
                b+="1";
            }
        }
        
        
        int cnt=0;
        
        // int k=0;
        
        for(int i=0;i<n;i++){
            
            if(a[i]==s[i]){
                continue;
            }else{
                cnt++;
            }
            
        }
        
        ans=min(ans,cnt);
        
        for(int i=n;i<m;i++){
            
            if(a[i-n]!=s[i-n]){
                cnt--;
            }
            
            if(a[i]!=s[i]){
                cnt++;
            }
            
            ans=min(ans,cnt);
            
        }
        
        cnt=0;
        
        for(int i=0;i<n;i++){
            
            if(b[i]==s[i]){
                continue;
            }else{
                cnt++;
            }
            
        }
        
        ans=min(ans,cnt);
        
        for(int i=n;i<m;i++){
            
            if(b[i-n]!=s[i-n]){
                cnt--;
            }
            
            if(b[i]!=s[i]){
                cnt++;
            }
            
            ans=min(ans,cnt);
            
        }
        
        return ans;
        
    }
};