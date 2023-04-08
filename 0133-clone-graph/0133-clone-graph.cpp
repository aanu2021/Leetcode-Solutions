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
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*>copies;
        Node*copy = new Node(node->val);
        copies[node] = copy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(Node*nbrs : curr->neighbors){
                if(copies.find(nbrs) == copies.end()){
                    copies[nbrs] = new Node(nbrs->val);
                    q.push(nbrs);
                }
                copies[curr]->neighbors.push_back(copies[nbrs]);
            }
        }
        return copy;
    }
};