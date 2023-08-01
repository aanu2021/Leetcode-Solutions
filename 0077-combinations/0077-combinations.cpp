class Solution {
public:
    
    vector<vector<int>>answer;
    
    void recursion(int idx,int cnt,int n,int k,vector<int>&solution){
        
        if(cnt > k) return;
        
        if(idx > n){
            if(cnt == k){
                answer.push_back(solution);
            }
            return;
        }
        
        recursion(idx+1,cnt,n,k,solution);
        
        solution.push_back(idx);
        recursion(idx+1,cnt+1,n,k,solution);
        solution.pop_back();
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        answer.clear();
        vector<int>solution;
        recursion(1,0,n,k,solution);
        return answer;
    }
};