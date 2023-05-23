//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
  
    unordered_map<int,int>indexMap;
    
    Node* BuildBT(int pre[],int preMirror[],int l1,int r1,int l2,int r2){
        
        if(l1 > r1 || l2 > r2) return NULL;
        if(l1 == r1 || l2 == r2) return new Node(pre[l1]);
        
        Node * root = new Node(pre[l1]);
        int index = indexMap[pre[l1+1]];
        
        int cntLeftSubtree = (r2-index+1);
        int cntRightSubtree = (r1-l1-cntLeftSubtree);
        
        root->left = BuildBT(pre,preMirror,l1+1,l1+cntLeftSubtree,index,r2);
        root->right = BuildBT(pre,preMirror,l1+cntLeftSubtree+1,r1,l2+1,l2+cntRightSubtree);
        
        return root;
        
    }
  
    Node* constructBinaryTree(int pre[], int preMirror[], int n)
    {
        
        indexMap.clear();
        
        for(int i=0;i<n;i++){
            indexMap[preMirror[i]] = i;
        }
        
        Node* root = BuildBT(pre,preMirror,0,n-1,0,n-1);
        
        return root;
        
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends