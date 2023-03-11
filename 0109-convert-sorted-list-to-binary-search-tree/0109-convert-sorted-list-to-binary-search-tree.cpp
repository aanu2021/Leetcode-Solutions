class Solution {
public:
    
    /* Preorder Traversal (Root -> Left -> Right) */
    
    TreeNode* sortedListToBST2(ListNode* head) {
        
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode * tempPtr = NULL;
        ListNode * slowPtr = head;
        ListNode * fastPtr = head;
        while(fastPtr && fastPtr->next){
            tempPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        tempPtr->next = NULL;
        TreeNode*root = new TreeNode(slowPtr->val);
        root->left = sortedListToBST2(head);
        root->right = sortedListToBST2(slowPtr->next);
        return root;
        
    }
    
    /*

    T(n) = 2*T(n/2) + n
    T(n/2) = 2*T(n/4) + (n/2)
    T(n/4) = 2*T(n/8) + (n/4)

    T(n/2) = 2*2*T(n/8) + n
    T(n) = 2^3 * T(n/2^3) + 3*n
    T(n) = 2^k * T(n/2^k) + k*n

    T(n) = n*O(1) + n*log2(n)
    T(n) = nlogn  

    Time Complexity  : O(N*logN)
    Space Complexity : O(1) 

    */

    
    /* Inorder Traversal (Left -> Root -> Right) */
    
    ListNode * head;
    
    TreeNode * recursion(int low,int high){
        if(low > high) return NULL;
        int mid = (low + high)/2;
        TreeNode * root = new TreeNode(-1);
        root->left = recursion(low,mid-1);
        root->val = head->val;
        head = head->next;
        root->right = recursion(mid+1,high);
        return root;
    }
    
    TreeNode * sortedListToBST(ListNode* head){
        
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        int n = 0;
        ListNode * ptr = head;
        while(ptr){
            n++; ptr = ptr->next;
        }
        
        this->head = head;
        return recursion(0,n-1);
        
    }
    
    /*
    
    T(n) = 2*T(n/2)
    T(n/2) = 2*T(n/2*2)
    T(n/4) = 2*T(n/2*2*2)
    T(n/2) = 2*2*T(n/2*2*2)
    T(n) = 2*2*2*T(n/2*2*2)
        
    T(n) = 2^k * T(n/2^k)
        
    k = log2(n)
        
    T(n) = 2^log2(n) * T(1)
    T(n) = n * O(1)
    T(n) = O(N)
        
    Time Complexity  : O(N)
    Space Complexity : O(1)  
    
    */
    
};

