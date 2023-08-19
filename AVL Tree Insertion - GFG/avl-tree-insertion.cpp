//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    
    int getHeight(Node* root){
        if(!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    int getBalanceFactor(Node* root){
        if(!root) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }
    
    Node*leftRotate(Node* x){
        Node*y = x->right;
        Node*T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }
    
    Node*rightRotate(Node* y){
        Node*x = y->left;
        Node*T2 = x->right;
        x->right = y;
        y->left = T2;
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return x;
    }
    
    Node* insertToAVL(Node* root, int data)
    {
        if(!root) return new Node(data);
        if(root->data < data){
            root->right = insertToAVL(root->right,data);
        }
        else if(root->data > data){
            root->left = insertToAVL(root->left,data);
        }
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        
        int bf = getBalanceFactor(root);
        
        // Left Left Case
        if(bf > 1 && root->left->data > data){
            return rightRotate(root);
        }
        
        // Right Right Case
        if(bf < -1 && root->right->data < data){
            return leftRotate(root);
        }
        
        // Left Right Case
        if(bf > 1 && root->left->data < data){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        // Right Left Case
        if(bf < -1 && root->right->data > data){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends