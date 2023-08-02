class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>answer;
        int first = nums[0], second = nums[0];
        int cnt1 = 1, cnt2 = 0;
        
        for(int i=1;i<n;i++){
            if(nums[i] == first){
                cnt1++;
            }
            else if(nums[i] == second){
                cnt2++;
            }
            else{
                if(cnt1 == 0){
                    cnt1 = 1;
                    first = nums[i];
                }
                else if(cnt2 == 0){
                    cnt2 = 1;
                    second = nums[i];
                }
                else{
                    cnt1--;
                    cnt2--;
                }
            }
        }
        
        cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == first) cnt1++;
            if(nums[i] == second) cnt2++;
        }
        
        if(cnt1 > (n/3)) answer.push_back(first);
        if(cnt2 > (n/3) && first != second) answer.push_back(second);
        return answer;
    }
};

/*

n%3 == 0 -->  atmost 2 majority elements [4,4,1]
n%3 == 1 -->  atmost 2 majority elements [4,4,2]
n%3 == 2 -->  atmost 2 majority elements [4,4,3]

number of majority elements must be in the range [0,2]

*/