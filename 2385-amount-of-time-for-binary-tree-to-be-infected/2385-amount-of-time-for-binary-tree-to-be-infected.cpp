class Solution {
public:
    
    void traverse(TreeNode* root, int lvl, int &maxTimer){
        if(!root) return;
        maxTimer = max(maxTimer, lvl);
        traverse(root->left, lvl+1, maxTimer);
        traverse(root->right, lvl+1, maxTimer);
    }
    
    int func(TreeNode* root, int start, int &maxTimer){
        if(!root) return -1;
        if(root->val == start){
            traverse(root, 0, maxTimer);
            return 1;
        }
        int L = func(root->left, start, maxTimer);
        if(L > -1){
            maxTimer = max(maxTimer, L);
            traverse(root->right, L + 1, maxTimer);
            return L + 1;
        }
        int R = func(root->right, start, maxTimer);
        if(R > -1){
            maxTimer = max(maxTimer, R);
            traverse(root->left, R + 1, maxTimer);
            return R + 1;
        }
        return -1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        int maxTimer = 0;
        func(root, start, maxTimer);
        return maxTimer;
    }
};