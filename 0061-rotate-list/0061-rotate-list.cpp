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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL || head->next==NULL || k==0) return head;
         int n = 1;
         ListNode*pointer = head;
         while(pointer && pointer->next){
             n++;
             pointer = pointer->next;
         }

         k = (k%n);
         k = (n-k);
         if(k==0 || k==n) return head;
         k--;

         pointer->next = head;

         ListNode*temp = head;
         while(k>0){
             temp = temp->next;
             k--;
         }

         head = temp->next; 
         temp->next = NULL; 
         return head;

    }
};

   
