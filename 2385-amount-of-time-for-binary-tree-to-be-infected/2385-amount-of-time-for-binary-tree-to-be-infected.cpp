class Solution {
public:
    
    void add_subtree(TreeNode* root, int lvl, int &maxTimer){
        if(!root) return;
        maxTimer = max(maxTimer, lvl);
        add_subtree(root->left, lvl + 1, maxTimer);
        add_subtree(root->right, lvl + 1, maxTimer);
    }
    
    int dfs(TreeNode* root, int start, int &maxTimer){
        if(!root) return -1;
        if(root->val == start){
            add_subtree(root,0,maxTimer);
            return 1;
        }
        int dist = dfs(root->left, start, maxTimer);
        if(dist > -1){
            maxTimer = max(maxTimer, dist);
            add_subtree(root->right, dist + 1, maxTimer);
            return dist + 1;
        }
        dist = dfs(root->right, start, maxTimer);
        if(dist > -1){
            maxTimer = max(maxTimer, dist);
            add_subtree(root->left, dist + 1, maxTimer);
            return dist + 1;
        }
        return -1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int maxTimer = 0;
        dfs(root, start, maxTimer);
        return maxTimer;
    }
};