class Solution {
public:
    
    void addSubtree(TreeNode* root, int k, vector<int>&answer){
        if(!root) return;
        if(k < 0) return;
        if(k == 0) answer.push_back(root->val);
        addSubtree(root->left, k-1, answer);
        addSubtree(root->right, k-1, answer);
    }
    
    int func(TreeNode* root, TreeNode* target, int k, vector<int>&answer){
        if(!root) return -1;
        if(root == target){
            addSubtree(root, k, answer);
            return k-1;
        }
        int L = func(root->left, target, k, answer);
        if(L >= 0){
            if(L == 0) answer.push_back(root->val);
            addSubtree(root->right, L-1, answer);
            return L-1;
        }
        int R = func(root->right, target, k, answer);
        if(R >= 0){
            if(R == 0) answer.push_back(root->val);
            addSubtree(root->left, R-1, answer);
            return R-1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        vector<int>answer;
        func(root, target, k, answer);
        return answer;
    }
};