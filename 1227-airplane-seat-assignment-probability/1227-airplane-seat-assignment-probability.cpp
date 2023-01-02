class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        else return 0.5;
    }
};


/*

Case 1 : P1 takes S1
Case 2 : P1 takes Sn
Case 3 : P1 takes S2/S3/S4.../Sn-1

Case 1 : probability = 1/n  (Taking exactly one seat out of n seats)

Case 2 : Probability = 0 (try to observe carefully if P1 takes the required seat Sn of Pn , then it is impossible for Pn in future to acquire his corresponding seat Sn)

Case 3 : Probability = (n-2)/n * 1/(n-2) * [f(n-1) + f(n-2) + ... + f(2)]

Sum of probabilities = f(n) = 1/n + 1/n * [f(2) + f(3) + ... + f(n-1)]

f(n) = 1/n * [f(1) + f(2) + f(3) + ... + f(n-1)]

n*f(n) = f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) .... (1)

f(n-1) = 1/(n-1) * [f(1) + f(2) + f(3) + ... f(n-2)]

(n-1)*f(n-1) = f(1) + f(2) + f(3) + ... + f(n-2) ..... (2)

Doing eq..n (1) - eq..n (2) ,

n*f(n) - n*f(n-1) + f(n-1) = f(n-1)

n*f(n) = n*f(n-1)

f(n) = f(n-1)

*/   