class Solution {
public:
    
    vector<TreeNode*>func(int start,int end){
        if(start > end){
            return {NULL};
        }
        if(start == end){
            return {new TreeNode(start)};
        }
        vector<TreeNode*>result;
        for(int i=start;i<=end;i++){
            auto leftArr = func(start,i-1);
            auto rightArr = func(i+1,end);
            for(auto &l : leftArr){
                for(auto &r : rightArr){
                    TreeNode*node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return func(1,n);
    }
};