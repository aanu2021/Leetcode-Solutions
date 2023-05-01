class Solution {
public:
    
    /*
    
    T.C : O(N*N)
    S.C : O(N*N)
    
    */
    
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
    
    /* ---------------------------------------------------- */
    
    /*
    
    T.C : O(N)
    S.C : O(N)
    
    */
    
    unordered_map<string,int>tripletMap;
    unordered_map<int,int>cntMap;
    vector<TreeNode*>result;
    
    int func2(TreeNode* &root){
        if(!root) return 0;
        
        string triplet = to_string(root->val) + "," + to_string(func2(root->left)) + "," + to_string(func2(root->right));
        
        if(tripletMap.find(triplet) == tripletMap.end()){
            tripletMap[triplet] = tripletMap.size() + 1;
        }
        
        int id = tripletMap[triplet];
        cntMap[id]++;
        if(cntMap[id]==2) result.push_back(root);
        return id;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root) return {};
        func2(root);
        return result;
    }
    
};