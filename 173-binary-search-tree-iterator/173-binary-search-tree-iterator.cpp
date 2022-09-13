class BSTIterator {
public:
    
    stack<TreeNode*>S;
    
    BSTIterator(TreeNode* root) {
        
        pushAll(root);
        
    }
    
    void pushAll(TreeNode*root){
        
        if(!root){
            return;
        }
        
        while(root){
            
            S.push(root);
            root=root->left;
            
        }
        
    }
    
    int next() {
        
        auto node=S.top();
        S.pop();
        
        int value=node->val;
        
        pushAll(node->right);
        
        return value;
        
    }
    
    bool hasNext() {
        
        return !S.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */