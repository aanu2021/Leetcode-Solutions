// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.

int func(int d,Node*head1,Node*head2){
    
    Node*current1=head1;
    
    for(int i=0;i<d;i++){
        if(current1==NULL){
            return -1;
        }
        current1=current1->next;
    }
    
    Node*current2=head2;
    
    while(current1!=NULL && current2!=NULL){
        
        if(current1==current2){
            return current1->data;
        }
        
        current1=current1->next;
        current2=current2->next;
        
    }
    
    return -1;
    
}

int countNode(Node*head){
    
    int n=0;
    
    while(head!=NULL){
        n++;
        head=head->next;
    }
    
    return n;
    
}

int intersectPoint(Node* head1, Node* head2)
{
    
    int c1=countNode(head1);
    int c2=countNode(head2);
    
    if(c1>c2){
        
        return func(c1-c2,head1,head2);
        
    }
    
    else{
        return func(c2-c1,head2,head1);
    }
    
}

