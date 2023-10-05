class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int ele1 = nums[0], ele2 = nums[0];
        int cnt1 = 1, cnt2 = 0;
        
        for(int i=1;i<n;i++){
            if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                if(cnt1 == 0){
                    cnt1 = 1;
                    ele1 = nums[i];
                }
                else if(cnt2 == 0){
                    cnt2 = 1;
                    ele2 = nums[i];
                }
                else{
                    cnt1--;
                    cnt2--;
                }
            }
        }
        
        vector<int>answer;
        cnt1 = 0, cnt2 = 0;
        for(int i=0;i<n;i++){
            cnt1 += (nums[i]==ele1);
            cnt2 += (nums[i]==ele2);
        }
        if(cnt1 > (n/3)){
            answer.push_back(ele1);
        }
        if(ele1 != ele2 && cnt2 > (n/3)){
            answer.push_back(ele2);
        }
        return answer;
    }
};

/*

n%3 == 0 -->  atmost 2 majority elements [4,4,1]
n%3 == 1 -->  atmost 2 majority elements [4,4,2]
n%3 == 2 -->  atmost 2 majority elements [4,4,3]

number of majority elements must be in the range [0,2]

*/