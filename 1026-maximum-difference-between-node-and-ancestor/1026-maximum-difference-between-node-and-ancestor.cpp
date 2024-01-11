class Solution {
public:
    
    int MIN = -1000000000;
    int MAX =  1000000000;
    
    // (Min, Max)
    pair<int,int> func(TreeNode* root, int &maxDiff){
        if(!root) return {MIN, MAX};
        if(!root->left && !root->right) return {root->val, root->val};
        pair<int,int> L = func(root->left,  maxDiff);
        pair<int,int> R = func(root->right, maxDiff);
        pair<int,int> C = {root->val, root->val};
        int currDiff = 0;
        if(root->left){
            currDiff = max(currDiff, abs(root->val - L.first));
            currDiff = max(currDiff, abs(root->val - L.second));
            C.first = min(C.first, L.first);
            C.second = max(C.second, L.second);
        }
        if(root->right){
            currDiff = max(currDiff, abs(root->val - R.first));
            currDiff = max(currDiff, abs(root->val - R.second));
            C.first = min(C.first, R.first);
            C.second = max(C.second, R.second);
        }
        maxDiff = max(maxDiff, currDiff);
        return C;
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxDiff = 0;
        func(root, maxDiff);
        return maxDiff;
    }
};