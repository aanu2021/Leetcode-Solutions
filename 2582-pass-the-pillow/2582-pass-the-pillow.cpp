class Solution {
public:
    int passThePillow(int n, int time) {
        int completeTurn = (time/(n-1));
        int remainingTime = (time%(n-1));
        if(completeTurn%2){
            return (n - remainingTime);
        }
        else{
            return (remainingTime + 1);
        }
    }
};



