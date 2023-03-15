class Solution {
public:
    
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool isNullFound = false;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(!node){
                isNullFound = true;
            }
            else{
                if(isNullFound){
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};