class Solution {
public:
    
    /*
    
    Let say the string str will be of length d , then we can easily say that , 
    
    num = str[0]*26^(d-1) + str[1]*26^(d-2) + str[2]*26^(d-3) + ... + str[d-1]*26^0
    
    now , we need to figure out how do we fetch those str[0] , str[1] , str[2] , str[3] values ???
    
    instead of accessing them from the left to right , what we can do is figure out the last character first (i.e str[d-1] , str[d-2] , str[d-3] and so on.....).
    
    Still we don't know how do we first fetch the last string character str[d-1].
    
    Let's use an important mathematical trick.
    
    x = (m*a) + b  [0 <= b < m]
    
    x%m = ( (m*a) + b) % m;
    
    x%m = ((m*a)%m) + (b%m)
    
    x%m = ((m%m)*(a%m))%m + (b%m)
    
    x%m = (0*(a%m))%m + (b%m)
    
    x%m = 0 + (b%m)
    
    x%m = b [ as b>=0 && b<m , therefore b%m must be equal to b ]
    
    
    Cool , now we will gonna use the same trick , but instead of 'x' , we'll use 'num'  and  in place of 'm' we will use '26'.
    
    See , num = 26*some number + str[d-1]*(26^0)
    
          num%26 = 0 + str[d-1]
          
          finally we get str[d-1] (i.e the last character of the string , then we will find out the second last character of the string , then the third last.....)
          
          But again , the question is how do we find out the second last character after str[d-1] , well for these again math is the saviour for sure.
          
          divide the num with 26 , and you will get
          
          num = str[0]*26^d-1 + str[1]*26^d-2 + ..... + str[d-2]*26^1 + str[d-1]
          
          num = num/26
          
          modified num = num/26
          
          num = str[0]*26^d-2 + str[1]*26^d-3 + ... + str[d-2]
          
          again do num%26 to figure out the current last(i.e overall second last character).
    
    */
    
    string convertToTitle(int num) {
        string res = "";
        while(num>0){
            num--;
            int rem = (num%26);
            res+=(char)(rem+'A');
            num/=26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
 
    
/*

T.C : O(log_26(N))
S.C : O(log_26(N))

*/
    
    
  