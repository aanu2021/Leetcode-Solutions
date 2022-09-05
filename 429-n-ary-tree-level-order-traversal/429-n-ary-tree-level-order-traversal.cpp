/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
       if(root==NULL){
           return {};
       }
        
        vector<vector<int>>result(1001);
        
        queue<Node*>q;
        q.push(root);
        
        int level=0;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                
                Node*node=q.front();
                q.pop();
                
                result[level].push_back(node->val);
                
                for(Node*child:node->children){
                    q.push(child);
                }
            }
            
            level++;
        }
        
        result.resize(level);
        
        return result;
        
    }
};