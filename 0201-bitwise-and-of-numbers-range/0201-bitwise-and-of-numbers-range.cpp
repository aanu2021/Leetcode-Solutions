/*

Time Complexity  : O(log(right))
Space Complexity : O(1)

Algorithm :->

(1) First check whether there exists a transition (0-->1 / 1-->0) at a particular bit position for any two consecutive elements in the given range.

(2) If transition exists , then the final bit will be set to zero(0) for that bit index , else set to one(1).

(3) Another major observation would be , if there is a transition at bit position 'i' , then definitely there is a transition at bit position 'i-1' , 'i-2' , 'i-3' , ...... , '0'.

(4) So we will traverse from the right side until and unless the left and right values are equal to each other.

10100 --> 1010 --> 101 left==right
10101 --> 1010 --> 101
10110 --> 1011 --> 101
10111 --> 1011 --> 101 right==left

(5) Finally , bitwise and for these range of numbers , [left...right] will be (remaining_left) after the right shift operations.

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int count = 0;
        
        while(left != right){
            left >>= 1;
            right >>= 1;
            count++;
        }
        
        return (left << count);
        
    }
};