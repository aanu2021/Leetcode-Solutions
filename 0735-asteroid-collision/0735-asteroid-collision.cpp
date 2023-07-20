class Solution {
public:
    
    bool goLeft(int ele){
        return ele < 0;
    }
    bool goRight(int ele){
        return ele > 0;
    }
    
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int>S;
        for(int i=0;i<n;i++){
            // No other asteriods left before that
            if(S.empty()){
                S.push(nums[i]);
                continue;
            }
            // No collision condition
            // LEFT + LEFT
            if(goLeft(S.top()) && goLeft(nums[i])){
                S.push(nums[i]);
                continue;
            }
            // LEFT + RIGHT
            if(goLeft(S.top()) && goRight(nums[i])){
                S.push(nums[i]);
                continue;
            }
            // RIGHT + RIGHT
            if(goRight(S.top()) && goRight(nums[i])){
                S.push(nums[i]);
                continue;
            }
            // Collision Condition
            bool asteriodDestroyed = false;
            while(!S.empty() && goRight(S.top()) && goLeft(nums[i])){
                int absLeftVal = abs(S.top());
                int absRightVal = abs(nums[i]);
                // Two same size asteriods collide each other
                if(absLeftVal == absRightVal){
                    S.pop();
                    asteriodDestroyed = true;
                    break;
                }
                if(absLeftVal > absRightVal){
                    asteriodDestroyed = true;
                    break;
                }
                else{
                    S.pop();
                }
            }
            if(!asteriodDestroyed){
                S.push(nums[i]);
            }
        }
        vector<int>answer;
        while(!S.empty()){
            answer.push_back(S.top()); S.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

/*

+ ->
- <-

Collisions does not occur

neg neg
neg pos
pos pos

Collisions does occur

pos neg

RIGHT  LEFT

*/
    
    