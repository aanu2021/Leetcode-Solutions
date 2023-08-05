class Solution {
public:
    
    vector<int>answer;
    
    void postorder(TreeNode* &root){
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        answer.push_back(root->val);
    }
    
    void postorder2(TreeNode* &root){
        stack<TreeNode*>S;
        S.push(root);
        while(!S.empty()){
            auto node = S.top(); S.pop();
            answer.push_back(node->val);
            if(node->left){
                S.push(node->left);
            }
            if(node->right){
                S.push(node->right);
            }
        }
        reverse(answer.begin(),answer.end());
    }
    
    void postorder3(TreeNode* &root){
        TreeNode*node = root;
        while(node){
            if(!node->right){
                answer.push_back(node->val);
                node = node->left;
            }
            else{
                TreeNode*curr = node->right;
                while(curr && curr->left && curr->left != node){
                    curr = curr->left;
                }
                if(!curr->left){
                    answer.push_back(node->val);
                    curr->left = node;
                    node = node->right;
                }
                else{
                    curr->left = NULL;
                    node = node->left;
                }
            }
        }
        reverse(answer.begin(),answer.end());
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        postorder3(root);
        return answer;
    }
};