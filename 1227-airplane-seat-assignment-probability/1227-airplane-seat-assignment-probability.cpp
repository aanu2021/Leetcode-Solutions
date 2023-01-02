class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1.0;
        else return 0.5;
    }
};

/*

1 2 3 4 5
    
1 -> 1.0
2 -> 0.5
3 -> 0.5
4 -> 0.5    
    
1 2 3  *  
2 1 3  *
2 3 1   
3 2 1   
    
1 2 3 4 *
2 1 3 4 *
2 3 1 4 *
2 3 4 1
2 4 3 1
3 2 1 4 *
3 2 4 1
4 2 3 1
 

There are two possible scenarios :

Case 1 : When first person takes the first seat.
         Then there is only one valid seat arrangement , and it is good seating arrangement as well.
    
Case 2 : When first person seat gets swapped with any of the person from person 2 to person n.
         
    2 1/3/4
    
    2 1 3 4
    2 3 4 1
    2 3 1 4
    2 4 3 1
    
    
*/   