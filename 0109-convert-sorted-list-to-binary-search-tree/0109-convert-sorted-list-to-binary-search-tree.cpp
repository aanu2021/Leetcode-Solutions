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
        
        TreeNode * root = new TreeNode(slowPtr->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slowPtr->next);
        
        return root;
        
    }
};

/*

T(n) = 2*T(n/2) + n
T(n/2) = 2*T(n/4) + (n/2)
T(n/4) = 2*T(n/8) + (n/4)
    
T(n/2) = 2*2*T(n/8) + n
T(n) = 2^3 * T(n/2^3) + 3*n
T(n) = 2^k * T(n/2^k) + k*n

T(n) = n*O(1) + n*log2(n)
T(n) = nlogn  

*/
