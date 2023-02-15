class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num1, int k) {
        vector<int>num2;
        while(k){
            num2.push_back(k%10);
            k/=10;
        }
        reverse(num2.begin(),num2.end());
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        vector<int>ans;
        int bit = 0,carry = 0;
        while(i>=0 || j>=0){
            bit = carry;
            if(i>=0){
                bit += num1[i];
                i--;
            }
            if(j>=0){
                bit += num2[j];
                j--;
            }
            carry = bit/10;
            bit = bit%10;
            ans.push_back(bit);
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};