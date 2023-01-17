class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int c1 = 0,c0 = 0;
        for(char ch:s){
            if(ch == '0') c0++;
            else          c1++;
        }
        // Convert whole string in "00000" / "11111" form
        int ans = min(c0,c1);
        c1 = 0;
        for(char ch:s){
            if(ch == '1') c1++;
            else          c0--;
            ans = min(ans,c1 + c0);
        }
        return ans;
    }
};

/*

0 1 0 1 1 0
    
let say the string is monotone increasing wrt index i , i.e

all the characters on the left side of index 'i' is '0'  &&
    
all the characters on the right side of index 'i' is '1'.
    
And we gonna call index 'i' as separator.
    
Consider a fixed separator 'i' , and at that point of time

we have c1 number of '1's on its left side , where they shouldn't reside.
    
As well as we have c0 number of '0's on its right side , where they shouldn't reside.
    
For visualization , 

Desired string should look like

 00000000 'i' 1111111
    
Current string is like

 011000101 'i' 00101101
    
 Now total number of operations required to make the string 
 
 monotone increasing wrt separator 'i' is (c1 + c0). why ???
    
 in one operation we can flip s[i] = '0' --> '1' / '1' --> '0'
    
 then we will definitely flip all the unnecessary '1's on left.
    
 And flip all the unnecessary '0's on its right.
    
 *** To make string string monotone inc wrt sep 'i' , 
     # of operations = (c1[left] + c0[right])

 *** Do the same computation for all index 'i' (0....n-1) , and
     take the minimum out of them. 
     
 *** Time Complexity  : O(N)
 
 *** Space Complexity : O(1)
     
*/     
     