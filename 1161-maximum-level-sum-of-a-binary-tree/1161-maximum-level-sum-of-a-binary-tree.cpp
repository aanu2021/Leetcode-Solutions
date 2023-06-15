class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return -1;
        
        queue<TreeNode*>q;
        q.push(root);
        
        int lvl = 1;
        int maxSum = INT_MIN;
        int index = 0;
        
        while(!q.empty()){
            int sz = q.size();
            int currSum = 0;
            while(sz--){
                auto node = q.front(); q.pop();
                currSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currSum > maxSum){
                maxSum = currSum;
                index = lvl;
            }
            lvl++;
        }
        
        return index;
        
    }
};