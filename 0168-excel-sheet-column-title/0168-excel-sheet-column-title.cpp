class Solution {
public:
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
 
    

    
    
  