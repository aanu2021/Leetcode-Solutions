/*

Time Complexity  : O(N)
Space Complexity : O(1)

Algorithm :-> 

1 ^ 0 = 1
0 ^ 1 = 1
1 ^ 1 = 0
0 ^ 0 = 0

a1,a2,a3,a2,a3,a1,a4,a5

a1 , a3 , a4 , a3 , a1

(1) Find out the xorval = (a1^a1^a2^a2^a3^a3^a4^a5) = (a4^a5)

(2) Find out the msb of xorval

(3) We can assure that there exists exactly one element with its msb set , provided it has exactly one occurence in the array.

(4) xor1 = a1 ^ a1 ^ a3 ^ a3 ^ a4 = a4
    xor2 = (xorval ^ xor1) = (a4 ^ a5 ^ a4) = a5
    
(5) ans = {a4 , a5}   

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        long long xorSum = 0;
        
        for(int i=0;i<n;i++){
            long long ele = abs(nums[i]);
            xorSum ^= ele;
        }
        
        int msb = log2(xorSum);
        long long num1 = 0, num2 = 0;
        
        for(int i=0;i<n;i++){
            long long ele = abs(nums[i]);
            if((ele&(1LL<<msb))){
                num1 ^= ele;
            }
        }
        
        int c1 = 0, c2 = 0;
        num2 = (xorSum ^ num1);
        
        for(int i=0;i<n;i++){
            if(nums[i] == num1){
                c1++;
            }
            if(nums[i] == num2){
                c2++;
            }
        }
        
        if(c1 != 1) num1 = -num1;
        if(c2 != 1) num2 = -num2;
        return {(int)num1, (int)num2};
    }
};

/*

1 1 2 2 3 5
    
1 ^ 1 ^ 2 ^ 2 ^ 3 ^ 5 = 6
    
3 ^ 5 = 6
    
1 1 0
    
5 , 6 ^ 5 = (5, 3)

*/