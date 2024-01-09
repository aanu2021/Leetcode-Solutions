class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>&vec){
        if(!root) return;
        inorder(root->left, vec);
        if(!root->left && !root->right) vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        inorder(root1, v1);
        inorder(root2, v2);
        int m = v1.size(), n = v2.size();
        if(m != n) return false;
        for(int i=0;i<n;i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};