class Solution {
public:
    
    vector<vector<int>>ans;
    
    void recursion(vector<int>&vec,int i,int n,int k,vector<int>&solution){
        
        if(k < 0) return;
        
        if(i==9){
            if(k==0 && n==0) ans.push_back(solution);
            return;
        }
        
        recursion(vec,i+1,n,k,solution);
        
        solution.push_back(vec[i]);
        recursion(vec,i+1,n-1,k-vec[i],solution);
        solution.pop_back();
        
    }
    
    vector<vector<int>> combinationSum3(int n, int k) {
        vector<int>vec;
        for(int i=1;i<=9;i++) vec.push_back(i);
        vector<int>solution;
        recursion(vec,0,n,k,solution);
        return ans;
    }
};