class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        s = "$" + s;
        p = "$" + p;
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            if(p[i] == '*') dp[0][i] = dp[0][i-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i] == p[j] || p[j] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

/*

? -> a single character
* -> any sequence of characters

s = a b a a c d c

p = ? b ? * c


func(s,p,i,j) --> 
    determines whether the prefix s[0...i] matches with 
    p[0...j] or not .
    

Case 1 : if (s[i] == p[j])  --> Last characters of both the 
prefixes matches with each other exactly. Then we need to check 
whether they are also a perfect match for the rest of the 
prefixes , i.e  s[0.....i-1] && p[0.....j-1]


Case 2 : if (p[j] == '?')  --> last character of prefix of 
string p can eat up (match) exactly one character (provided in
the question) . Then we have only one way to match both the 
prefixes. Match s[i] with p[j] = '?' , as it has the power to
match exactly one character. Now we are left with matching rest
of the prefixes , i.e  s[0.....i-1] && p[0.....j-1]


Case 3 : if(p[j] == '*')  --> Now here comes the trickiest part 
of the problem . Using '*' power we can match any sequence of 
character , i.e  if the prefix for string s , i.e s[0...i] is 
something like prefix_of_s = "ababaa"
    
And we have '*' at the end of the prefix_of_p. Then we have
multiple ways to chech the exact match between both the strings

Way1 : Match no character (empty sequence) then we are left 
with checking just s[0...i] && p[0...j-1]

Way2 : Match one character from the end of prefix_of_s , and 
    left with checking s[0...i-1] && p[0...j-1]

Way3 : .... s[0...i-2] && p[0...j-1]

Way4 : .... s[0...i-3] && p[0...j-1]

and so on ......................
    
Then for Case 3 , one thing we can say , to make sure whether
two prefixes are exact match or not , we need to explore all 
the possible ways (Way1 , Way2 , ....) and if any one of them 
produce the exact match , then that's it.
    

But , but , but .....................
    
Can we further optimize the Case3 , let us see it once.
    
we have multiple ways to check for the exact match , i.e way1 ,
way2 , way3 , way4 , and so on ....
    
func( s[0...i] && p[0...j] ) -->
    
func( s[0...i] && p[0...j-1]) || func(s[0...i-1]) && p[0...j-1]) || func(s[0...i-2] && p[0...j-1]) || func(s[0...i-3] && p[0...j-1]) || .....
    
Now we need to explore all the ways just because , we discard
the power of '*' character in each and every way , what does it
mean ?? 
    
s = a b a b a

p = a b *

ababa | ab*

(abab | ab*)
    
(aba | ab*)
    
(ab | ab*)
    
 finally we can consider '*' as an empty sequence and it is an
 exact match .
    
So what I mean by this example is do not shift the j-th index
by 1 (i.e j -> j-1) , just let it reside with us , until and 
    unless we get the exact sequence before it and can consider
    '*' as an empty sequence.
    
Modified Case3 : s[0...i] && p[0...j] --> s[0...i-1] && 
                p[0...j] --> s[0...i-2] && p[0...j] --> ....    

    Time Complexity  : O(N*N)
    Space Complexity : O(N*N)    
    
*/
