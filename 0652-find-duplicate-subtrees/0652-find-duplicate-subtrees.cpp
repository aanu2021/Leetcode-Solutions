class Solution {
public:
    
    unordered_map<string,vector<TreeNode*>>flattenNodes;
    
    string func(TreeNode*& root){
        if(!root) return "";
        string str = to_string(root->val);
        str += "[";
        str += func(root->left);
        str += ",";
        str += func(root->right);
        str += "]";
        flattenNodes[str].push_back(root);
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        func(root);
        vector<TreeNode*>answer;
        for(auto&itr : flattenNodes){
            if(itr.second.size() > 1){
                answer.push_back(itr.second[0]);
            }
        }
        return answer;
    }
};