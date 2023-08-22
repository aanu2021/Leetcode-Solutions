class Solution {
public:
    
    void recursion(vector<int>&nums,vector<int>&fact,int n,int k,string &ans){
        if(n==1){
            ans += (char)(nums[0]+'0');
            return;
        }
        int idx = (k/fact[n-1]);
        ans += (char)(nums[idx]+'0');
        nums.erase(nums.begin()+idx);
        k -= (idx*fact[n-1]);
        recursion(nums,fact,n-1,k,ans);
    }
    
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>nums(n);
        vector<int>fact(n+1);
        k--;
        fact[0] = 1;
        for(int i=1;i<=n;i++) fact[i] = fact[i-1]*i;
        for(int i=0;i<n;i++) nums[i] = i+1;
        recursion(nums,fact,n,k,ans);
        return ans;
    }
};