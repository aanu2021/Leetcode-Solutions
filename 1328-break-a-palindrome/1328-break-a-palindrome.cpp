/*

Approach 1 : Brute Force 

Algorithm : Convert every character of a string between 'a' to 'z' And then check whether it is a palindrome or not , if it is a
palindrome , then we can't do anything . Else , if it is not a 
palindrome , as of now our first criteria gets matched , its the 
time to figure out the lexicographically smallest one out of all
possibilities.

T.C : O(N*26)
S.C : O(N) --> for the string that we gonna return

*/

/*

Approach 2 : Greedy + Observation

Algorithm : Now we need to think us a greedy person :)

See , in the question they ask to find out the lexicographically smallest string . If there is no such constraints (it must not be a palindrome , exactly one move is given to us , etc.) , in that scenario , we will fill all the n charcters as "aaaa...aaa" (n times) . 

Now start adding constraints , we are bound to use the move exactly one times. So , what if we are in search of the character which is not equal to 'a' from the left of the string , and convert it into 'a'. e.g: "aabccbaa" , 'b' is the first character which is not equal to 'a' , in order to achieve lex smallest string we will change that . "aabccbaa" --> "aaaccbaa"

Hmmmm , as of now we are left with only one constraint , that is the resultant string must not be a palindrome . Wait , initially a string is given to us where s[i] = s[n-i-1] (0 <= i <= n/2).
If we change the first non 'a' character with 'a' , that means s[i]='a' and s[n-i-1]!='a' , which clearly implies that it is no longer a palindrome.

But , what we will do for the strings like "aaaaaa" , "aaaaa" . We can't convert any non 'a' character , we will change the last character of the string as 'b' [second smallest character after 'a']. e.g - "aaaaaa" --> "aaaaab".

T.C : O(N)
S.C : O(N)

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
        
      //  return breakPalindrome2(s);
        
        int n = s.length();
        
        if(n==1){
            return "";
        }
        
        string temp = s;
        
        for(int i=0;i<n/2;i++){
            
            if(n%2 && i==n/2) continue;
            
            if(s[i]!='a'){
                s[i] = 'a';
                break;
            }
            
        }
        
        // Above Mentioned Edge Case "aaaaa" //
        
        if(s==temp){
            s[n-1] = 'b';
        }
        
        return s;
        
    }
    
};