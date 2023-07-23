class Solution {
public:
    
    vector<TreeNode*>solve(int n){
        vector<TreeNode*>answer;
        if(n==1){
            return {new TreeNode(0)};
        }
        for(int i=0;i<n;i++){
            int x = i,y = n-i-1;
            if(x%2==0 || y%2==0) continue;
            for(auto l : solve(x)){
                for(auto r : solve(y)){
                    TreeNode*node = new TreeNode(0);
                    node->left = l;
                    node->right = r;
                    answer.push_back(node);
                }
            }
        }
        return answer;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        return solve(n);
    }
};