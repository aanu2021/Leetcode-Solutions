//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

typedef long long ll;
const ll INF = 1e15;
const ll NINF = -1e15;

struct Pair{
  
  ll mini;
  ll maxi;
  ll sum;
  ll Size;
  ll isBST;
    
};

class Solution {
public:

    Pair func(Node*& root,int &minLen,int target){
        
        if(!root) return {INF,NINF,0LL,0LL,1LL};
        
        auto left = func(root->left,minLen,target);
        auto right = func(root->right,minLen,target);
        Pair curr;
        
        curr.isBST = 0;
        curr.sum = root->data + left.sum + right.sum;
        curr.Size = 1 + left.Size + right.Size;
       
        if(left.isBST && right.isBST){
            if(left.maxi < root->data && right.mini > root->data){
                curr.isBST = 1;
            }
        }
        
        curr.mini = min({(ll)root->data,left.mini,right.mini});
        curr.maxi = max({(ll)root->data,left.maxi,right.maxi});
        
        if(curr.isBST && curr.sum == target){
            minLen = min(minLen,(int)curr.Size);
        }
        // cout<<curr.sum<<" "<<curr.Size<<" "<<curr.isBST<<"\n";
        return curr;
    }

    int minSubtreeSumBST(int target, Node *root) {
        if(!root) return -1;
        int minLen = INT_MAX;
        func(root,minLen,target);
        return minLen==INT_MAX ? -1 : minLen;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends