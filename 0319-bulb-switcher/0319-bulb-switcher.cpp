class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};


/*

Hints :->
    
    1. i-th bulb will be on at the end of the n-th round,
       if and only if it gets toggled odd number of times.
           
    2. According to the problem, when we encounter the i-th
       round, we can toggle every i-th bulb in the series.
           
    3. That means, on the j-th bulb, there must be the effect 
       of all the bulbs i (where i is a divisor of j)
           
    4. For example, if j = 12, we can toggle the j-th bulb
       6 times (i=1, i=2, i=3, i=4, i=6, i=12).
        
    5. That means the problem boils down to -> count the number
       of bulbs, which have their divisor count as odd.
        
    6. Now comes the important observation, that we can make,
       if we dry run for all the n(upto 20), that only those
       bulbs have odd number of divisors, which are perfect 
       square of any number. (e.g - 1,4,9,16,25.....)
           
*/           
