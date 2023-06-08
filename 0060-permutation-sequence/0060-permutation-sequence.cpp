class Solution {
public:
    
    void func(vector<int>&nums,vector<int>&fact,int n,int k,string &ans){
        
        if(n==1){
            ans += (char)(nums[0]+'0');
            return;
        }
        
        int idx = k/fact[n-1];
        
        ans += (char)(nums[idx] + '0');
        
        nums.erase(nums.begin()+idx);
        
        k -= (idx*fact[n-1]);
        
        func(nums,fact,n-1,k,ans);
        
    }
    
    string getPermutation(int n, int k) {
        
        k--;
        
        vector<int>nums;
        vector<int>fact(n+1,0);
        
        fact[0] = 1;
        
        for(int i=1;i<=n;i++){
            fact[i] = fact[i-1]*i;
            nums.push_back(i);
        }
        
        string ans = "";
        
        func(nums,fact,n,k,ans);
        
        return ans;
        
    }
};

