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
        Node*copy = new Node(node->val);
        copies[node] = copy;
        for(auto &nbr : node->neighbors){
            if(copies.find(nbr) == copies.end()){
                copies[nbr] = new Node(nbr->val);
                cloneGraph(nbr);
            }
            copies[node]->neighbors.push_back(copies[nbr]);
        }
        return copy;
    }
};