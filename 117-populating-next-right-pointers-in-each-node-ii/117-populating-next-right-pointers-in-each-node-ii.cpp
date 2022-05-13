/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL){
            return NULL;
        }
        
        Node*head=root;
        
        while(head){
            
            Node*dummy=new Node(-1);
            Node*temp=dummy;
            
            while(head){
                
                if(head->left!=NULL){
                    temp->next=head->left;
                    temp=temp->next;
                }
                
                if(head->right!=NULL){
                    temp->next=head->right;
                    temp=temp->next;
                }
                
                head=head->next;
                
            }
            
            head=dummy->next;
            
        }
        
        return root;
        
    }
};