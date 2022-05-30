class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n=s.length();
        
        vector<vector<int>>prefix(n+1,vector<int>(26,0));
        
        for(int i=0;i<n;i++){
            
            int j=s[i]-'a';
            
            prefix[i][j]++;
            
        }
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<26;j++){
                
                prefix[i][j]+=prefix[i-1][j];
                
            }
            
        }
        
        
        int ans=0;
        
        map<char,int>firstidx;
        map<char,int>lastidx;
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(firstidx.find(ch)==firstidx.end()){
                firstidx[ch]=i;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            char ch=s[i];
            if(lastidx.find(ch)==lastidx.end()){
                lastidx[ch]=i;
            }
        }
        
        
        for(char ch1='a';ch1<='z';ch1++){
            
            for(char ch2='a';ch2<='z';ch2++){
                
                int i=firstidx[ch1];
                int j=lastidx[ch1];
                
                if(i==j){
                    continue;
                }
                
                int middle_occ=(j-1>=0 ? prefix[j-1][ch2-'a'] : 0)-(i>=0 ? prefix[i][ch2-'a'] : 0);
                
                if(middle_occ>=1){
                    ans++;
                }
                
            }
            
        }
        
        return ans;
        
    }
};