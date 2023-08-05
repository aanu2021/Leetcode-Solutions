class Solution {
public:
    
    vector<vector<int>>answer;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        answer.clear();
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>levelArr(sz);
            int l = 0, r = sz-1;
            while(sz--){
                auto node = q.front(); q.pop();
                if(lvl%2==0){
                    levelArr[l++] = node->val;
                }
                else{
                    levelArr[r--] = node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            answer.push_back(levelArr);
            lvl++;
        }
        return answer;
    }
};