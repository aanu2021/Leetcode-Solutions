class Solution {
public:
    
    bool IsValid(vector<int>&v){
        int n = v.size();
        for(int i=1;i<n;i++){
            if(v[i] < v[i-1]) return false;
        }
        return true;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>S;
        for(int i=0;i<(1<<n);i++){
            int cnt = __builtin_popcount(i);
            if(cnt < 2) continue;
            vector<int>v;
            for(int j=0;j<n;j++){
                if((i&(1<<j))){v.push_back(nums[j]);}
            }
            if(IsValid(v)){
                if(S.find(v)==S.end()){
                    S.insert(v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};