class Solution {
public:
    
    void dfs(TreeNode*& root,int lvl,vector<int>&answer){
        if(!root) return;
        if(answer.size() == lvl){
            answer.push_back(root->val);
        }
        else{
            answer[lvl] = max(answer[lvl], root->val);
        }
        dfs(root->left,lvl+1,answer);
        dfs(root->right,lvl+1,answer);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int>answer;
        if(!root) return answer;
        dfs(root,0,answer);
        return answer;
    }
};