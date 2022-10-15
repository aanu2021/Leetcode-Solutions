class Solution {
public:
    int findSubstringInWraproundString(string s) {
        
        int n = s.length();
        
        vector<int>arr(26,0);
        
        int currLen = 0;
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            
            int curr = s[i]-'a';
            
            if(i>0){
                
                int prev = (curr-1+26)%26;
                
                if(s[i-1]!=(char)(prev+'a')){
                    
                    currLen = 0;
                    
                }
                
            }
            
            currLen++;
            
            if(arr[curr] < currLen){
                
                ans+=(currLen - arr[curr]);
                
                arr[curr] = currLen;
                
            }
            
        }
        
        return ans;
        
    }
};