class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ops = 0;
        
        for(int i=31;i>=0;i--){
            if((c&(1<<i))){
                if((a&(1<<i))==0 && (b&(1<<i))==0){
                    ops++;
                }
            }
            else{
                if((a&(1<<i))) ops++;
                if((b&(1<<i))) ops++;
            }
        }
        
        return ops;
        
    }
};