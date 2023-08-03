class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(vector<int>&nums,int index,int n){
        if(index == n){
            answer.push_back(nums);
            return;
        }
        for(int i=index;i<n;i++){
            swap(nums[i],nums[index]);
            recursion(nums,index+1,n);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        recursion(nums,0,n);
        return answer;
    }
};