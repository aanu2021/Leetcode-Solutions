class Solution {
public:
    
    bool isSymRec(TreeNode*&p , TreeNode*&q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSymRec(p->left,q->right) && isSymRec(p->right,q->left);
    }
    
    bool isSymIter(TreeNode* &root){
        queue<TreeNode*>p,q;
        p.push(root->left);
        q.push(root->right);
        while(!p.empty() || !q.empty()){
            auto r1 = p.front(); p.pop();
            auto r2 = q.front(); q.pop();
            if(!r1 && !r2) continue;
            if(!r1 || !r2) return false;
            if(r1->val != r2->val) return false;
            p.push(r1->left);
            p.push(r1->right);
            q.push(r2->right);
            q.push(r2->left);
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        // return isSymRec(root->left,root->right);
        return isSymIter(root);
    }
};