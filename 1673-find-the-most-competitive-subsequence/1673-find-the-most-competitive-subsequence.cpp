class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n = nums.size();
        stack<int>S;
        k = n-k;
        
        for(int i=0;i<n;i++){
            while(!S.empty() && S.top() > nums[i] && k>0){
                k--;
                S.pop();
            }
            S.push(nums[i]);
        }
        
        while(!S.empty() && k>0){
            S.pop();
            k--;
        }
        
        vector<int>answer;
        while(!S.empty()){
            answer.push_back(S.top());
            S.pop();
        }
        
        reverse(answer.begin(),answer.end());
        return answer;
        
    }
};