class Solution {
public:
    
    char prev_char(int currval){
        
        return (char)(((currval-1+26)%26)+'a');
        
    }
    
    int findSubstringInWraproundString(string s) {
        
        int n = s.length();
        
        vector<int>arr(26,0);
        
        int currLen = 0;
        
        int ans = 0;
        
        
        for(int i=0;i<n;i++){
            
            int curr = s[i] - 'a';
            
            char prev = prev_char(curr);
            
            if(i>0 && s[i-1]!=prev){
                
                currLen = 0;
                
            }
            
            currLen++;
            
            if(currLen > arr[curr]){
                
                ans += (currLen - arr[curr]);
                
                arr[curr] = currLen;
                
            }
            
        }
        
        return ans;
        
    }
};