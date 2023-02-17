class Solution {
public:
    
    void inorderTraversal(TreeNode*&root,int &prev,int &minDiff){
        if(!root) return;
        inorderTraversal(root->left,prev,minDiff);
        if(prev != -1){
            minDiff = min(minDiff,root->val - prev);
        }
        prev = root->val;
        inorderTraversal(root->right,prev,minDiff);
    }
    
    int minDiffInBST2(TreeNode* root) {
        if(!root) return 0;
        int minDiff = INT_MAX;
        int prev = -1;
        inorderTraversal(root,prev,minDiff);
        return minDiff;
    }
    
    int minDiffInBST(TreeNode* root){
        if(!root) return 0;
        int minDiff = INT_MAX;
        int prev = -1;
        TreeNode * curr = root;
        while(curr){
            if(curr->left == NULL){
                if(prev != -1){
                    minDiff = min(minDiff,curr->val - prev);
                }
                prev = curr->val;
                curr = curr->right;
            }
            else{
                TreeNode * prevNode = curr->left;
                while(prevNode && prevNode->right && prevNode->right != curr){
                    prevNode = prevNode->right;
                }
                if(prevNode->right == NULL){
                    prevNode->right = curr;
                    curr = curr->left;
                }
                else{
                    prevNode->right = NULL;
                    if(prev != -1){
                        minDiff = min(minDiff,curr->val - prev);
                    }
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return minDiff;
    }
    
};