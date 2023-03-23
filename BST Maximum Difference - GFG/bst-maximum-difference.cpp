//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int findLowerSum(Node *&root){
        if(!root) return 0;
        int curr = root->data;
        int extra = INT_MAX;
        if(root->left){
            extra = min(extra,findLowerSum(root->left));
        }
        if(root->right){
            extra = min(extra,findLowerSum(root->right));
        }
        if(extra == INT_MAX) extra = 0;
        return curr + extra;
    }

    void dfs(Node *&root,int target,int upperSum,bool &found,int &maxDiff){
        if(!root) return;
        if(found) return;
        if(root->data == target){
             found = true;
             int lowerSum = findLowerSum(root);
             maxDiff = max(maxDiff,upperSum-lowerSum+root->data);
             return;
        }
        else{
             dfs(root->left,target,upperSum+root->data,found,maxDiff);
             dfs(root->right,target,upperSum+root->data,found,maxDiff);   
        }
    }

    int maxDifferenceBST(Node *root,int target){
        if(!root) return -1;
        bool found = false;
        int maxDiff = INT_MIN;
        dfs(root,target,0,found,maxDiff);
        if(found) return maxDiff;
        else return -1;
    }
};

// first check if target node already exists
// if target node is not present , then return -1
// otherwise find our the sum from the root node to target node
// and now we are left with the sum from the target node to any of its leaf node.
// we have to choose the minimum sum from target node to any possible leaf node.
// equation ==>  difference = upperSum - lowerSum
// upperSum = sum from root node to target node
// lowerSum -> this factor is not fixed , so we have to minimize this term as much as possible.



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends