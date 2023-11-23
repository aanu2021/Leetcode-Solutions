class Solution {
public:
    
    bool isArithmeticSubarray(vector<int>&nums){
        int n = nums.size();
        int minElement = *min_element(nums.begin(),nums.end());
        int maxElement = *max_element(nums.begin(),nums.end());
        if((maxElement-minElement)%(n-1)) return false;
        int D = (maxElement-minElement)/(n-1);
        unordered_set<int>S;
        if(D == 0){
            for(int num : nums) S.insert(num);
            return S.size() == 1;
        }
        else{
            for(int num : nums){
                if((num-minElement)%D) return false;
                int index = (num-minElement)/D;
                if(S.find(index) != S.end()) return false;
                S.insert(index);
            }
            return true;
        }
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool>answer(m, false);
        for(int i=0;i<m;i++){
            int left  = l[i];
            int right = r[i];
            vector<int>vec;
            for(int index=left;index<=right;index++){
                vec.push_back(nums[index]);
            }
            answer[i] = isArithmeticSubarray(vec);
        }
        return answer;
    }
};