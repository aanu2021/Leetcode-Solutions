class Solution {
public:
   vector<vector<int>>dp;
    int find_ans(int i,int j,vector<int>&nums,vector<int>&mul,int n){
            int R=n-(j-i)-1;
        if(j==mul.size() or i>R)return 0;
        if(dp[i][j]!=INT_MIN)return dp[i][j];
     
        int op1=find_ans(i+1,j+1,nums,mul,n)+nums[i]*mul[j];
        int op2=find_ans(i,j+1,nums,mul,n)+nums[R]*mul[j];
        return dp[i][j]=   max(op1,op2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
       

       int n=nums.size();
       int m=multipliers.size();
      dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return find_ans(0,0,nums,multipliers,n);
    }
};