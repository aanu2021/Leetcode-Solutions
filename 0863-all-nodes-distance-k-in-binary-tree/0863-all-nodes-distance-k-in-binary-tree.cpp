class Solution {
public:
    
    vector<int>answer;
    
    void add_subtree(TreeNode*& root,int dist){
        if(!root) return;
        if(dist == 0){
            answer.push_back(root->val);
            return;
        }
        add_subtree(root->left,dist-1);
        add_subtree(root->right,dist-1);
    }
    
    int dfs(TreeNode*& root,TreeNode*& target,int k){
        if(!root) return -1;
        if(root == target){
            add_subtree(root,k);
            return k-1;
        }
        int dist = dfs(root->left,target,k);
        if(dist > -1){
            if(dist == 0) answer.push_back(root->val);
            add_subtree(root->right,dist-1);
            return dist-1;
        }
        dist = dfs(root->right,target,k);
        if(dist > -1){
            if(dist == 0) answer.push_back(root->val);
            add_subtree(root->left,dist-1);
            return dist-1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,target,k);
        return answer;
    }
};