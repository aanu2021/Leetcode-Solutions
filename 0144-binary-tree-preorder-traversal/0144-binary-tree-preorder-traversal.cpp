class Solution {
public:
    
    vector<int>answer;
    
    void preorder(TreeNode* &root){
        if(!root) return;
        answer.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    void preorder2(TreeNode* &root){
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty()){
            auto node = S.top();
            S.pop();
            answer.push_back(node->val);
            if(node->right){
                S.push(node->right);
            }
            if(node->left){
                S.push(node->left);
            }
        }
    }
    
    void preorder3(TreeNode* &root){
        TreeNode*node = root;
        while(node){
            if(!node->left){
                answer.push_back(node->val);
                node = node->right;
            }
            else{
                TreeNode*curr = node->left;
                while(curr && curr->right && curr->right != node){
                    curr = curr->right;
                }
                if(!curr->right){
                    curr->right = node;
                    answer.push_back(node->val);
                    node = node->left;
                }
                else{
                    curr->right = NULL;
                    node = node->right;
                }
            }
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        preorder3(root);
        return answer;
    }
};