class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root){
            return "";
        }
        
        string str="";
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        str+=to_string(root->val);
        str+=",";
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            if(node==NULL){
                continue;
            }
            
            if(node->left){
                
                str+=to_string(node->left->val);
                str+=",";
                
            }else{
                
                str+="#,";
                
            }
            
            if(node->right){
                
                str+=to_string(node->right->val);
                str+=",";
                
            }else{
                
                str+="#,";
                
            }
            
            q.push(node->left);
            q.push(node->right);
            
        }
        
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.length()==0){
            return NULL;
        }
        
        stringstream s(data);
        
        string str;
        
        getline(s,str,',');
        
        TreeNode*root=new TreeNode(stoi(str));
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str=="#"){
                node->left=NULL;
            }else{
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            
            getline(s,str,',');
            
            if(str=="#"){
                node->right=NULL;
            }else{
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
            
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));