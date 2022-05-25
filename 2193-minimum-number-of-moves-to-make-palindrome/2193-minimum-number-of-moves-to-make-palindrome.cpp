class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int n=s.length();
        
        int ans=0;
        
        int left=0,right=n-1;
        
        while(left<right){
            
            if(s[left]==s[right]){
                left++;
                right--;
                continue;
            }
            
            int l=left;
            int r=right;
            
            while(s[l]!=s[r]){
                r--;
            }
            
            if(l==r){
                swap(s[r],s[r+1]);
                ans++;
                continue;
            }
            
            for(int j=r;j<right;j++){
                
                swap(s[j],s[j+1]);
                ans++;
                
            }
            
            left++;
            right--;
            
        }
        
        return ans;
        
    }
};