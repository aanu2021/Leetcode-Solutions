class Solution {
public:
    
    /*
    
    Solution Approach : 
    
    (1) Order of the operations are not important.
    
    e.g - aAbBCc --> [aA]bBCc --> bB[Cc] --> [bB] --> ""
          aAbBCc --> aA[bB]Cc --> [aA]Cc --> [Cc] --> ""
          aAbBCc --> aAbB[Cc] --> aA[bB] --> [aA] --> ""
          
       That means no matter how we perform the adjacent character 
       deletion , at the end of the day all of them produce the same
       resultant string.
       
       
     (2) Stack aproach is quite intuitive , Why we just need the 
     last character that is not deleted in our string , and then 
     compare it with the current character , if they Match (lower + 
     upper / upper + lower) , then don't add the current character ,
     and delete the last remaining character as well.
     
     e.g - aAbBCc 
     
           currently we have 'a' as our last character , and 'A' as
           our current character , then as they matched with each 
           other , remove the last character , and skip the current 
           character as well.
           
     Time Complexity  : O(N) 
     Space Complexity : O(N)
     
     
     (3) That is one of the optimized approach , but is it the 
     ultimate one ?? Definitely not......
     
     We can further reduce the space complexity.
     
     As I mentioned earlier , what we need to keep track is the last
     character that is not deleted , and compare it with the current
     character , if they matched then delete tha last one , and skip
     the current one(as both of them are deleted) , otherwise add 
     the current character.
     
     Can we use a two pointer , where we use left , right pointers.
     
     And what are their significance ???
     
     right pointer points out to the current character , left 
     pointer points out to the last character , that is not deleted
     till now + 1 .
     
     l e E e e t
     0 1 2 3 4 5
     
     left = 0
     right = 0
     
     first check can we get the last character (left>0) , now we 
     can't.
     
     just leave the 0-th character as it is. and move both the right
     and left pointers.
     
     left = 1
     right = 1
     
     Compare s[left-1] with s[right] , do they match ?? no.....
     
     again move the left , right pointer.
     
     left = 2
     right = 2
     
     Compare s[left-1] with s[right] , do they match ?? yessss.....
     
     it is the tricky part of these algorithm , now instead of 
     deleting s[left-1] and s[right] characters , we will decrease 
     the left pointer and increment the right pointer , as if we 
     skip the current character and delete the last character.
     
     Time Complexity  : O(N)
     Space Complexity : O(1)
    
    */
    
    string makeGood(string s) {
       
        int n = s.length();
        int left = 0, right = 0;
        
        for(right=0;right<n;right++){
            
            if(left>0 && abs(s[left-1]-s[right])==32){
                left--;
            }else{
                s[left] = s[right];
                left++;
            }
            
        }
        return s.substr(0,left);
        
    }
};


  