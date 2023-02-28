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
    
    vector<TreeNode*> findDuplicateSubtrees2(TreeNode* root) {
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
    
    unordered_map<string,int>tuplet;
    unordered_map<int,int>cnt;
    vector<TreeNode*>result;
    
    int func2(TreeNode*& root){
        if(!root) return 0;
        string currComp = to_string(func2(root->left)) + to_string(root->val) + to_string(func2(root->right));
        if(tuplet.find(currComp) == tuplet.end()){
            tuplet[currComp] = tuplet.size() + 1;
        }
        int id = tuplet[currComp];
        cnt[id]++;
        if(cnt[id] == 2){
            result.push_back(root);
        }
        return id;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        func2(root);
        return result;
    }
    
};