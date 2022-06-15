/* 

The Question can be solved with the help of two or three approaches , including bfs , dp and so on.

  But the most efficient and little bit tricky approach is greedy.
  
  
   Now we have to sort the strings in the increasing order of 
         their length , then we have to pick each and every string from 
         the extreme left to extreme right . When we are at a string
         (lets say str) , we have to traverse the string str and one by one 
         delete every character and check whther it is found beforehand or not.
         
         e.g : str = " b d c a " [ See Sample Example 1 ]
         
         first , delete 0-th indexed 'b' --> new_str = " d c a " [new_str is not found previously].
         
         second , delete 1-st indexed 'd' --> new_str = " b c a " [new_str is found previously ].
         
         third , delete 2-nd indexed 'c' --> new_str = " b d a " [ new_str is found  previously ] .
         
         fourth , delete 3-rd indexed 'a' --> new_str = " b d c " [ new_str is not found previously ].
         
         
         Here we can observe that we are able to form 4 kind of new strings , "dca" ,"bca" , "bda" , "bdc" respectively . Among all the strings "bca" and "bda" are already found in the [words] set. So , we can easily reach the string "bda" / "bca" from "bdca" , then recursively find the same thing for "bca" / "bda" .......
         
         
         Now why we sort the strings in the increasing order of their length , 
         
  well , if you observe carefully we can only insert a single charcater in a string
  
  , and that is equivalent to delete a single charcater from a string to get the
  
  older one.
  
   e.g : "abcd" --> erase 'c' at index 2 --> "abd" . is equivalent to
         "abd" --> insert 'c' at index 2 --> "abcd".
         
         
         And if we are able to make some groups of string with respect to their length , like group1 ( all the strings of length 1 ) , group2 ( all the strings 
 of length 2 ) , and so on.....
 
     And a string of length L cab be reduced to only string of length (L-1) , not less than these , not even more than these , so sorting enables these feature to solve the problem efficiently.
         
  
  */

class Solution {
public:
    
    bool static comp(const string&s1 , const string&s2){
        
        return s1.length() < s2.length();
        
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        
        map<string,int>mp;
        
        sort(words.begin(),words.end(),comp);
        
        int maxLen=0;
        
        for(string str:words){
            
            string temp=str;
            
            for(int i=0;i<str.length();i++){
                
                temp=str;
                
                temp.erase(i,1);
                
                if(mp.find(temp)!=mp.end()){
                    mp[str]=max(mp[str],mp[temp]+1);
                }else{
                    mp[str]=max(mp[str],1);
                }
                
            }
            
            maxLen=max(maxLen,mp[str]);
            
        }
        
        return maxLen;
        
    }
};