class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(vector<int>&nums,int index,int n){
        if(index==n){
            answer.push_back(nums);
            return;
        }
        unordered_set<int>S;
        for(int i=index;i<n;i++){
            if(S.find(nums[i]) != S.end()) continue;
            S.insert(nums[i]);
            swap(nums[i],nums[index]);
            recursion(nums,index+1,n);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        answer.clear();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        recursion(nums,0,n);
        return answer;
        
    }
};