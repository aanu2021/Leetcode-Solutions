class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(vector<int>&nums,int i,vector<int>&solution,int n){
        answer.push_back(solution);
        
        for(int j=i;j<n;j++){
            if(j!=i && nums[j]==nums[j-1]){
                continue;
            }
            solution.push_back(nums[j]);
            recursion(nums,j+1,solution,n);
            solution.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        answer.clear();
        sort(nums.begin(),nums.end());
        vector<int>solution;
        recursion(nums,0,solution,n);
        return answer;
    }
};