class BSTiterator{
  
    private:
    
    stack<TreeNode*>S;
    bool reverse;
    
    public:
    
    BSTiterator(TreeNode*root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    
    void pushAll(TreeNode * root){
        while(root){
            S.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    
    int next(){
        auto node = S.top(); S.pop();
        int value = node->val;
        if(reverse) pushAll(node->left);
        else        pushAll(node->right);
        return value;
    }
    
    bool hasNext(){
        return !S.empty();
    }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            int sum = i + j;
            if(sum == k)     return true;
            else if(sum > k) j = r.next();
            else             i = l.next(); 
        }
        return false;
    }
};