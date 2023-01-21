class BSTIterator {
public:
    
    stack<TreeNode*>S;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    void pushAll(TreeNode * root){
        while(root){
            S.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto node = S.top(); S.pop();
        int value = node->val;
        if(node->right) pushAll(node->right);
        return value;
    }
    
    bool hasNext() {
        return !S.empty();
    }
};

