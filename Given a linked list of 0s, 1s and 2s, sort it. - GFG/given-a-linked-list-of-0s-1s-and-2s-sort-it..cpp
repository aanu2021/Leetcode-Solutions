//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(!head || !head->next) return head;
        
        vector<int>vec;
        
        while(head){
            vec.push_back(head->data);
            head = head->next;
        }
        
        Node*dummy = new Node(-1);
        Node*temp = dummy;
        
        int n = vec.size();
        int low = 0, mid = 0, high = n-1;
        
        while(mid <= high){
            if(vec[mid]==0){
                swap(vec[low],vec[mid]);
                low++;
                mid++;
            }
            else if(vec[mid]==1){
                mid++;
            }
            else{
                swap(vec[mid],vec[high]);
                high--;
            }
        }
        
        for(int &ele : vec){
            temp->next = new Node(ele);
            temp = temp->next;
        }
        return dummy->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends