//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node*reverseHead(Node* head){
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
    
    Node *compute(Node *head)
    {
        if(!head) return NULL;
        head = reverseHead(head);
        // do something
        Node*temp = NULL;
        Node*ptr = head;
        int maxValue = -1;
        while(ptr){
            int value = ptr->data;
            if(value < maxValue){
                temp->next = ptr->next;
                ptr = temp->next;
            }
            else{
                maxValue = max(maxValue,value);
                temp = ptr;
                ptr = ptr->next;
            }
        }
        head = reverseHead(head);
        return head;
    }
    
};

// 3 2 6 5 11 10 15 12

// 3 6 11 15
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends