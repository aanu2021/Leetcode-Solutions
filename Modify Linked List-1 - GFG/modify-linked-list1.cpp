//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    
    Node * reverseList(Node* &head){
        
        if(!head || !head->next) return head;
        
        Node*prevptr = NULL;
        Node*currptr = head;
        Node*nextptr = NULL;
        
        while(currptr){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        
        return prevptr;
        
    }
    
    struct Node* modifyTheList(struct Node *head)
    {
        
        if(!head || !head->next) return head;
        
        Node * slow = head;
        Node * fast = head;
        Node * slowHead = NULL;
        
        while(fast && fast->next){
            slowHead = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slowHead->next = NULL;
        
        Node*current = slow;
        
        slow = reverseList(slow);
        
        Node * temp1 = head;
        Node * temp2 = slow;
        
        while(temp1 && temp2){
            int value = temp1->data;
            temp1->data = temp2->data - temp1->data;
            temp2->data = value;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        slow = reverseList(slow);
        
        slowHead->next = slow;
        
        return head;
        
    }
};




//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends