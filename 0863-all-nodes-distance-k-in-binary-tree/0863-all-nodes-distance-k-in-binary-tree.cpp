class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>parent;
    
    void findParent(TreeNode* &root){
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        findParent(root->left);
        findParent(root->right);
    }
    
    vector<int> bfsTraversal(TreeNode* &src,int k){
        vector<int>ans;
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(src);
        while(!q.empty() && k>=0){
            int sz = q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                if(visited.find(node) != visited.end()) continue;
                visited.insert(node);
                if(k==0)
                ans.push_back(node->val);
                if(parent.find(node) != parent.end()) q.push(parent[node]);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            k--;
        }
        return ans;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        findParent(root);
        vector<int> ans = bfsTraversal(target,k);
        return ans;
    }
};