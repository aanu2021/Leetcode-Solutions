class Solution {
public:
    
    void inorderRecursive(TreeNode* root,vector<int>& answer){
        if(!root) return;
        inorderRecursive(root->left, answer);
        answer.push_back(root->val);
        inorderRecursive(root->right, answer);
    }
    
    void inorderIterative(TreeNode* root,vector<int>& answer){
        if(!root) return;
        stack<TreeNode*>S;
        TreeNode*curr = root;
        while(!S.empty() || curr){
            while(curr){
                S.push(curr);
                curr = curr->left;
            }
            TreeNode*current = S.top(); S.pop();
            answer.push_back(current->val);
            if(current->right) curr = current->right;
        }
    }
    
    void inorderMorisTraversal(TreeNode* root, vector<int>& answer){
        if(!root) return;
        TreeNode*curr = root;
        while(curr){
            if(curr->left == NULL){
                answer.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode*leftNode = curr->left;
                while(leftNode && leftNode->right && leftNode->right != curr){
                    leftNode = leftNode->right;
                }
                if(leftNode->right == NULL){
                    leftNode->right = curr;
                    curr = curr->left;
                }
                else{
                    answer.push_back(curr->val);
                    leftNode->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        inorderMorisTraversal(root,answer);
        // inorderIterative(root,answer);
        // inorderRecursive(root,answer);
        return answer;
    }
};