class Solution {
public:
    
    void recursion(vector<int>&nums,vector<int>&fact,string &ans,int n,int k){
        if(n==1){
            ans += (char)(nums[0] + '0');
            return;
        }
        int idx = (k/fact[n-1]);
        ans += (char)(nums[idx] + '0');
        nums.erase(nums.begin() + idx);
        k -= (idx*fact[n-1]);
        recursion(nums,fact,ans,n-1,k);
    }
    
    string getPermutation(int n, int k) {
        
        string ans = "";
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i] = i+1;
        }
        
        vector<int>fact(n+1);
        fact[0] = 1;
        for(int i=1;i<=n;i++){
            fact[i] = fact[i-1]*i;
        }
        k--;
        recursion(nums,fact,ans,n,k);
        return ans;
    }
};

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
  
// 1 4
    
// k = 0
    
// 2 3 1 4     
    
    