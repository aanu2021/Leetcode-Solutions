/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode* curr;
    BSTIterator(TreeNode* root) {
        curr=root;
    }
    int morrisTraversal(){
        int ans;
        while(curr){
        if(!curr->left){
            ans=curr->val;
            curr=curr->right;
            break;
        }
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr) prev=prev->right;
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                ans=curr->val;
                curr=curr->right;
                break;
            }
        }
    }
        return ans;
    }
    int next() {
        return morrisTraversal();
    }
    
    bool hasNext() {
        return !curr==NULL;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */