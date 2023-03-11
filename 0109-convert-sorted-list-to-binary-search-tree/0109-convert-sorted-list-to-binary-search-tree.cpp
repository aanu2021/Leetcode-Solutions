/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void printNodes(ListNode*head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }cout<<"\n";
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
       
        ListNode * slowPtr = head;
        ListNode * fastPtr = head;
        ListNode * tempPtr = NULL;
        
        while(fastPtr && fastPtr->next){
            tempPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        tempPtr->next = NULL;
        ListNode * leftSubtree = head;
        ListNode * rightSubtree = slowPtr->next;
        TreeNode * root = new TreeNode(slowPtr->val);
        
        // cout<<root->val<<"\n";
        // printNodes(leftSubtree);
        // printNodes(rightSubtree);
        
        root->left = sortedListToBST(leftSubtree);
        root->right = sortedListToBST(rightSubtree);
        return root;
    }
};