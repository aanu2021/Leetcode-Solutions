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
    
    void insert(ListNode*&head,int data){
   ListNode*n=new ListNode(data);
        
        if(head==NULL){
       head=n;
        return;
        }
        
        ListNode*ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
      }
        
        ptr->next=n;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
      ListNode*t=list1;
        int i=0;
        while(i!=b+1){
          t=t->next;
            i++;
        }
        ListNode*head=new ListNode();
        ListNode*temp=head;
        int j=0;
        while(j!=a){
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
            j++;
        }
        
        while(list2!=NULL){
            temp->next=list2;
            list2=list2->next;
            temp=temp->next;
        }
        
        while(t!=NULL){
            temp->next=t;
            t=t->next;
            temp=temp->next;
        }
        
        return head->next;
    }
};