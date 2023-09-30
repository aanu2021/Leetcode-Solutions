class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int>S;
        int second = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i] < second){
                return true;
            }
            while(!S.empty() && nums[i] > S.top()){
                second = S.top();
                S.pop();
            }
            S.push(nums[i]);
        }
        return false;
    }
};

/*

3 1 4 2
    
i < j < k
nums[i] < nums[k] < nums[j]

a < b < c < d

x < c < d

second = b

x > a
x > b

first = 
second = 
    
    first  -> minimize
    second -> maximize
    
    
    
1 4 2
1 < 2 < 4   

*/