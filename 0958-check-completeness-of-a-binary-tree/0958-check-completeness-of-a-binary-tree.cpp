class Solution {
public:
    
    int countNodes(TreeNode* &root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isComplete(TreeNode*& root,int index,int n){
        if(!root) return true;
        if(index >= n) return false;
        return isComplete(root->left,2*index+1,n) && isComplete(root->right,2*index+2,n);
    }
    
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        return isComplete(root,0,countNodes(root));
    }
};