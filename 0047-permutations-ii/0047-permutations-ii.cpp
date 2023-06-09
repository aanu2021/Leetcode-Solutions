class Solution {
public:
    
    set<vector<int>>st;
    vector<vector<int>>answer;
    
    void func(vector<int>&nums,int index,int n){
        
        if(index == n){
            if(st.find(nums) == st.end()){
                answer.push_back(nums);
                st.insert(nums);
            }
            return;
        }
        
        for(int i=index;i<n;i++){
            swap(nums[index],nums[i]);
            func(nums,index + 1,n);
            swap(nums[index],nums[i]);
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        func(nums,0,n);
        
        return answer;
        
    }
};