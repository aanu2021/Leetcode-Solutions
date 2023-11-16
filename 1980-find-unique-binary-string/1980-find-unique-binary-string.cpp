class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>S;
        for(int i=0;i<n;i++){
            S.insert(nums[i]);
        }
        for(int i=0;i<(1<<n);i++){
            string str = "";
            int num = i;
            for(int j=n-1;j>=0;j--){
                if((num&(1<<j))){
                    str += "1";
                }
                else{
                    str += "0";
                }
            }
            if(S.find(str) == S.end()){
                return str;
            }
        }
        return "";
    }
};