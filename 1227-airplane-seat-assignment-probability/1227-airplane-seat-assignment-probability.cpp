class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        else return 0.5;
    }
};

/*

P1 P2 P3 P4 P5 .... Pn-1 Pn
S1 S2 S3 S4 S5 .... Sn-1 Sn

Case 1 : P1 takes S1
Case 2 : P1 takes Sn
Case 3 : P1 takes either of S2/S3/S4/.../Sn-1

Probability of Case 1 : Taking exactly one seat from n number of seats == 1/n

Probability of Case 2 : Taking Sn seat will leave no way for Pn to acquire his  desired seat in future , so probability = 0

Probability of Case 3 : Taking (n-2) seats in cosideration from total n seats having probability = (n-2)/n . And to get the probability of good seating arrangement 1/(n-2) * [f(n-1) + f(n-2) + f(n-3) + ... + f(2)]

f(n) = 1/n + 1/n * [f(2) + f(3) + ... + f(n-1)]
f(n) = 1/n * [1 + f(2) + f(3) + ... + f(n-1)]
f(n) = 1/n * [f(1) + f(2) + f(3) + ... + f(n-1)] {as f(1) = 1}
n*f(n) = f(1) + f(2) + f(3) + .... + f(n-2) + f(n-1)

similarly for n-1 number of seats,

(n-1)*f(n-1) = f(1) + f(2) + f(3) + ... + f(n-2)

Now , 
n*f(n) - n*f(n-1) + f(n-1) = f(n-1)
n*f(n) = n*f(n-1)
f(n) = f(n-1)

*/