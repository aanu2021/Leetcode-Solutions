class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>levels;
        int lvl = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>level(sz);
            int i = 0;
            if(lvl%2) i = sz-1;
            while(sz--){
                auto node = q.front();
                q.pop();
                if(lvl%2 == 0){
                    level[i++] = node->val;
                }
                else{
                    level[i--] = node->val;
                }
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            lvl++;
            levels.push_back(level);
        }
        return levels;
    }
};