class Solution {
public:
    
    void func(int n,int k,vector<int>&nums,vector<int>&fact,string&ans){
        
        if(n==1){
            ans+=to_string(nums[0]);
            return;
        }
        
        int idx=k/fact[n-1];
        
        ans+=to_string(nums[idx]);
        
        nums.erase(nums.begin()+idx);
        
        k-=(idx*fact[n-1]);
        
        func(n-1,k,nums,fact,ans);
        
    }
    
    string getPermutation(int n, int k) {
        
        if(n==1){
           return "1";
        }
        
        k--;
        
        string ans="";
        
        vector<int>nums;
        
        vector<int>fact(n+1);
        
        fact[0]=1;
        
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            fact[i]=fact[i-1]*i;
        }
        
        func(n,k,nums,fact,ans);
        
        return ans;
        
    }
};