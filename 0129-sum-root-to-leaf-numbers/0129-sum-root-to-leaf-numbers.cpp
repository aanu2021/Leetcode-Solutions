class Solution {
public:
    
    void dfsRec(TreeNode*& root,int currSum,int &totalSum){
        if(!root) return;
        currSum = (currSum*10) + (root->val);
        if(!root->left && !root->right) totalSum += currSum;
        dfsRec(root->left,currSum,totalSum);
        dfsRec(root->right,currSum,totalSum);
    }
    
    int dfsIter(TreeNode*& root){
        stack<pair<TreeNode*,int>>S;
        S.push({root,root->val});
        int totalSum = 0;
        while(!S.empty()){
            
            int currSum = S.top().second;
            auto node = S.top().first;
            S.pop();
            
            if(!node->left && !node->right) totalSum += currSum;
            if(node->left) S.push({node->left,(currSum*10) + (node->left->val)});
            if(node->right) S.push({node->right,(currSum*10) + (node->right->val)});
            
        }
        
        return totalSum;
    }
    
    void Morris(TreeNode*& root,int &totalSum){
        int currSum = 0;
        int depth = 0;
        while(root){
            if(root->left == NULL){
                currSum = (currSum*10) + root->val;
                if(root->right == NULL) totalSum += currSum;
                root = root->right;
            }
            else{
                TreeNode * prev = root->left;
                depth = 1;
                while(prev && prev->right && prev->right != root){
                    prev = prev->right;
                    depth++;
                }
                if(prev->right == NULL){
                    prev->right = root;
                    currSum = (currSum*10) + (root->val);
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    if(!prev->left) totalSum += currSum;
                    currSum /= pow(10,depth);
                    root = root->right;
                }
            }
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int totalSum = 0;
        // dfsRec(root,0,totalSum);
        // return totalSum;
        // return dfsIter(root);
        Morris(root,totalSum);
        return totalSum;
    }
};