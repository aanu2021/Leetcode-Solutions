class Solution {
public:
    int numberOfChild(int n, int k) {
        int round = k/(n-1);
        int extra = k%(n-1);
        if(round%2){
            return (n-extra-1);
        }
        else{
            return (extra);
        }
    }
};

// 6/4 = 1
// 6%4 = 2
