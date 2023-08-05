class Solution {
public:
    
    vector<int>answer;
    
    void inorder(TreeNode* &root){
        if(!root) return;
        inorder(root->left);
        answer.push_back(root->val);
        inorder(root->right);
    }
    
    void inorder2(TreeNode* &root){
        stack<TreeNode*>S;
        TreeNode*node = root;
        while(node){
            S.push(node);
            node = node->left;
        }
        while(!S.empty()){
            auto curr = S.top(); S.pop();
            answer.push_back(curr->val);
            if(curr->right){
                curr = curr->right;
                while(curr){
                    S.push(curr);
                    curr = curr->left;
                }
            }
        }
    }
    
    void inorder3(TreeNode* &root){
        TreeNode*node = root;
        while(node){
            if(!node->left){
                answer.push_back(node->val);
                node = node->right;
            }
            else{
                TreeNode * curr = node->left;
                while(curr && curr->right && curr->right != node){
                    curr = curr->right;
                }
                if(!curr->right){
                    curr->right = node;
                    node = node->left;
                }
                else{
                    answer.push_back(node->val);
                    curr->right = NULL;
                    node = node->right;
                }
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        inorder3(root);
        return answer;
    }
};