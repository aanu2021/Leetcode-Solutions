/*

Approach 1 : Brute Force 

Algorithm : Convert every character of a string between 'a' to 'z' And then check whether it is a palindrome or not , if it is a
palindrome , then we can't do anything . Else , if it is not a 
palindrome , as of now our first criteria gets matched , its the 
time to figure out the lexicographically smallest one out of all
possibilities.

T.C : O(N*26)
S.C : O(N) // for the string that we gonna return

*/

class Solution {
public:
    
    string breakPalindrome2(string s){
        
        int n = s.length();
        
        // Trivial Case //
        
        if(n==1) return "";
        
        string res = "";
        
        for(int i=0;i<n;i++){
            
            /* Edge Case : for odd length string like abdba , 
            even if we change the character 'd' with any other 
            character still it will remain as a palindrome */
            
            if(n%2 && i==n/2) continue;
            
            char prev = s[i];
            
            for(char ch='a';ch<='z';ch++){
                
                // We can't use the same character like before 
                
                if(ch==prev) continue;
                
                s[i] = ch;
                
                if(res==""){
                    res = s;
                }else{
                    res = min(res,s);
                }
                
            }
            
            // Reset current character as before 
            
            s[i] = prev;
            
        }
        
        return res;
        
    }
    
    string breakPalindrome(string s) {
        
        return breakPalindrome2(s);
        
    }
    
};