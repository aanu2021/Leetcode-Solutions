/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>copies;
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node * copy = new Node(node->val);
        copies[node] = copy;
        for(auto &nbrs : node->neighbors){
            if(copies.find(nbrs) == copies.end()){
                copies[nbrs] = new Node(nbrs->val);
                cloneGraph(nbrs);
            }
            copies[node]->neighbors.push_back(copies[nbrs]);
        }
        return copy;
    }
};