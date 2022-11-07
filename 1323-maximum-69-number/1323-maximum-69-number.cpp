class Solution {
public:
    int reverse_num(int num){
        int res=0;
        while(num){
            res=(res*10)+(num%10);
            num/=10;
        }
        return res;
    }
    int maximum69Number (int num) {
        bool flag = true;
        int res = 0;
        num=reverse_num(num);
        while(num>0){
            int rem = (num%10);
            if(rem==9){
                res=(res*10)+rem;
            }else{
                if(flag){
                    res=(res*10)+9;
                    flag = false;
                }else{
                    res=(res*10)+rem;
                }
            }
            num/=10;
        }
        //res=reverse_num(res);
        return res;
    }
};