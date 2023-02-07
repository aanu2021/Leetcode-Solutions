class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<2*n;i++){
            int currNum = nums[i];
            int currPos = i;
            while(currNum > 0){
                int nextNum , nextPos;
                if(currPos < n) nextPos = 2 * currPos;
                else            nextPos = 2 * (currPos - n) + 1;
                nextNum = nums[nextPos];
                nums[nextPos] = -currNum;
                currNum = nextNum;
                currPos = nextPos;
            }
        }
        for(int i=0;i<2*n;i++){
            if(nums[i] < 0) nums[i] = -nums[i];
        }
        return nums;
    }
};

/*

2 5 1 3 4 7
0 1 2 3 4 5
    
currNum =  5     nextNum =   
currPos =  1     nextPos =      
    
if(currPos < n) nextPos = 2 * currPos
else            nextPos = 2 * (currPos - n) + 1

-2 -3 -5 -4 -1 -7    
    
2 3 5 4 1 7    
0 1 2 3 4 5    
    
*/    