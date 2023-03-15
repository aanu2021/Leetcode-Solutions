class Solution {
public:
    bool isCompleteTree2(TreeNode* root) {
        
        if(!root) return true;
        
        queue<TreeNode*>q;
        q.push(root);
        bool isNullFound = false;
        
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(!node) isNullFound = true;
            else{
                if(isNullFound) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
    
    int countNodes(TreeNode*& root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isComplete(TreeNode*& root,int index,int n){
        if(!root) return true;
        if(index >= n) return false;
        return isComplete(root->left,2*index + 1,n) && isComplete(root->right,2*index + 2,n);
    }
    
    bool isCompleteTree(TreeNode* root){
        
        if(!root) return true;
        return isComplete(root,0,countNodes(root));
        
    }
    
};