class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int n=s.length();
        
        int left = 0 , right = n-1;
        
        int ans = 0;
        
        while(left < right){
            
            if(s[left] == s[right]){
                
                left++;
                right--;
                continue;
                
            }
            
            int l = left;
            int r = right;
            
            while(s[l]!=s[r]){
                r--;
            }
            
            if(l==r){
                
                ans++;
                swap(s[r],s[r+1]);
                continue;
                
            }
            
            for(int i=r;i<right;++i){
                swap(s[i],s[i+1]);
                ans++;
            }
            
            left++;
            right--;
            
        }
        
        return ans;
        
    }
};


/*
l e t t e l
0 1 2 3 4 5
    i j 
    */