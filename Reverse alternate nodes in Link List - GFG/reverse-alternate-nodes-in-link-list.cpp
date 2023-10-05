//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    struct Node*reverseLL(struct Node *head){
        if(!head || !head->next) return head;
        Node*prevptr = NULL;
        Node*current = head;
        Node*nextptr = NULL;
        while(current){
            nextptr = current->next;
            current->next = prevptr;
            prevptr = current;
            current = nextptr;
        }
        return prevptr;
    }
    
    void printNodes(struct Node *head){
        while(head){
            cout<<head->data<<" ";
            head = head->next;
        }cout<<"\n";
    }
    
    void rearrange(struct Node *head)
    {
        if(!head || !head->next || !head->next->next) return;
        Node*ptr = head;
        Node*revptr = new Node(-1);
        // printNodes(revptr);
        Node*temp = revptr;
        while(ptr){
            if(ptr->next){
                temp->next = ptr->next;
                temp = temp->next;
                ptr->next = ptr->next->next;
            }
            ptr = ptr->next;
        }
        temp->next = NULL;
        revptr = revptr->next;
        revptr = reverseLL(revptr);
        // printNodes(revptr);
        Node*pointer = head;
        while(pointer && pointer->next){
            pointer = pointer->next;
        }
        pointer->next = revptr;
    }
};

// 10 4 9 1 3 5 9 4

// 10 9 3 9 4 5 1 4



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends